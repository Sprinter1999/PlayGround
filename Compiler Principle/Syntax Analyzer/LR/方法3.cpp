#include<iostream>
#include<iomanip>
#include<stack>
#include<string> 
using namespace std;

stack<char> s;                                           //栈 
char terminal[9]={'+','-','*','/','(',')','i','n','$'};  //终结符表 
char unterminal[3]={'E','T','F'};                        //非终结符表 
char grammar[10][10]={                                   //输出产生式 
     "SE","EE+T","EE-T","ET","TT*F",
     "TT/F","TF","Fi","F(E)","Fn"
     };
int Goto[17][3]={                           //手动构造LR()语法预测分析表
     1,2,3,0,0,0,0,0,0,0,0,0,
     0,0,0,11,2,3,0,0,0,0,12,3,
     0,13,3,0,0,14,0,0,15,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,
     };
int Action[17][9]={
     0,0,0,0,5,0,4,6,0,
     7,8,0,0,0,0,0,0,-10,
     -3,-3,9,10,0,-3,0,0,-3,
     -6,-6,-6,-6,0,-6,0,0,-6,
     -7,-7,-7,-7,0,-7,0,0,-7,
     0,0,0,0,5,0,4,6,0,
     -9,-9,-9,-9,0,-9,0,0,-9,
     0,0,0,0,5,0,4,6,0,
     0,0,0,0,5,0,4,6,0,
     0,0,0,0,5,0,4,6,0,
     0,0,0,0,5,0,4,6,0,
     7,8,0,0,0,16,0,0,0,
     -1,-1,9,10,0,-1,0,0,-1,
     -2,-2,9,10,0,-1,0,0,-2,
     -4,-4,-4,-4,0,-4,0,0,-4,
     -5,-5,-5,-5,0,-5,0,0,-5,
     -8,-8,-8,-8,0,-8,0,0,-8,
     };
char str[30];                       //待分析的输入表达式
int len;                            //待分析的输入表达式的长度 

void Get_str(void)                  //获取待分析输入表达式 
{ 
    printf("请输入待分析的表达式：");
    scanf("%s",&str);
    
    for(len=0;str[len]!='\0';len++);
    str[len]='$';
    str[len+1]='\0';
    len++;
    s.push('0');
    }

int Judge_id(char ch)  //判断字符是否为构成id的字母
{
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        return 1;
    else
        return 0;
    }

int Judge_num(char ch)  //判断字符是否为构成num的数字                
{
    if(ch>='0'&&ch<='9')
        return 1;
    else
        return 0;   
    }

void Output_stack(void)  //打印当前栈中的符号
{
	char st[30];
	int i,j=0,number=s.size();
	
    for(i=0;i<number;i++)
    {
        st[i]=s.top();
        s.pop();
        }
    for(i=number-1;i>=0;i--)
    {
        if(st[i]=='i')
        {
           cout<<"id";
           j+=1;
           }
        else if(st[i]=='n')
        {
           cout<<"num";         
           j+=2;
           }
        else if(st[i]>'9'&&st[i]<'9'+10)
           cout<<st[i]-'0';
        else
           cout<<st[i];
        s.push(st[i]);
        }
    for(i=0;i<8-j-number;i++)
        cout<<" ";
    }

void Output_buffer(int ip)  //打印当前输入缓冲区中的符号串
{
    int i,j;
    
    cout<<"\t";
    for(i=ip;str[i]!='$';i++)
        cout<<str[i];
    cout<<"$";
    for(j=0;j<8-i+ip;j++)
        cout<<" ";
    }

int Get_ternum(char ch)   //返回终结符在终结符表中的下标 
{
    int i;
    for(i=0;i<9;i++)
       if(ch==terminal[i])
          return i;
    return -1;
    }

int Get_unternum(char ch)  //返回非终结符在非终结符表中的下标 
{
    int i;
    for(i=0;i<3;i++)
       if(ch==unterminal[i])
          return i;
    return -1;
    }

int Judge_ter(char ch)      //判断字符是否为终结符 
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='i'||ch=='n'||ch=='$')
       return 1;
    else
       return 0;    
    }

int Judge_unter(char ch)    //判断字符是否为非终结符 
{
    if(ch=='E'||ch=='P'||ch=='T'||ch=='Q'||ch=='F')
       return 1;
    else
       return 0;
    }

void Analyse_output(void)      //使用LR()语法预测分析表分析输入的表达式并输出分析结果 
{
    int i,j,n,m;
    int S,step=0,ip=0,length=0;  
    int tag1=0,tag2=0;
    char a,c,b[20],st[20];
    
    cout<<"步骤"<<"\t栈\t\t"<<"输入\t"<<"\t分析动作\t\n";
    do 
	{
        step++;
        printf ("第%d步\t",step);
        S=s.top()-'0';          //获取栈顶符号 
        a=str[ip];              //获取输入串中将要进行分析的符号
        for(i=0;i<=20;i++)
            b[i]='\0';
        if(a=='+'||a=='-'||a=='*'||a=='/'||a=='('||a==')'||a=='$')
            length=1;
        else                    //处理输入表达式中代表id和num的子串，分别将它们转化为'i'和'n'进行分析     
		{
            j=ip; 
            length=0;    
            if(Judge_id(a)) 
                tag1=tag2=1;
            if(Judge_num(a))
                tag1=tag2=2;
            j++;
            c=a;
            do 
			{
                length++;
                b[length-1]=c;
                c=str[j];
                if(Judge_id(c))
                    tag2=1;
                else if(Judge_num(c))
                    tag2=2;
                else
                    tag2=0;
                j++;
                } while (tag1==tag2);
            if(tag1==1) 
                a='i';
            if(tag1==2)
                a='n';    
            }
        Output_stack();              //打印当前栈中的符号
        Output_buffer(ip);           //打印当前输入缓冲区中的符号串          
        m=Get_ternum(a);
        if(Action[S][m]>0)   
		{
            s.push(a);               //把a入栈 
            c='0'+Action[S][m];
            s.push(c);               //把S'入栈 
            ip+=length;              //推进ip，使它指向下一个输入符合 
            cout<<"\tShift"<<Action[S][m]<<"\t";
            }
        else if(Action[S][m]<0&&Action[S][m]!=-10)
		{
            i=0-Action[S][m];
            for(j=1;grammar[i][j]!='\0';j++)          //从栈顶弹出2*|B|符号 
            {
               s.pop();
               s.pop();
               }
            m=s.top()-'0';
            s.push(grammar[i][0]);                    //入栈 
            j=Get_unternum(grammar[i][0]);
            c='0'+Goto[m][j];
            s.push(c);
            cout<<"\treduce by "<<grammar[i][0]<<"→";
            for(j=1;grammar[i][j]!='\0';j++)          //输出产生式 
            {
               if(grammar[i][j]=='i')
                  cout<<"id";
               else if(grammar[i][j]=='n')
                  cout<<"num";
               else
                  cout<<grammar[i][j];
               }
            cout<<"\t";
            }
        else if(Action[S][m]==-10)
        {
            cout<<"\tacc\t\n";
            return; 
            }
        else
        {
            cout<<"\t错误!\t\n";
            return;
            }
        cout<<"\n";         
        }while(1);
    }

int main()
{
    Get_str();
    Analyse_output();
    
    system("pause");
    return 0;
    }
