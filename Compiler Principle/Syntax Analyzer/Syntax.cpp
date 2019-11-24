#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
using namespace std;

stack<char> Stack;
// 终结符号集,i表示identifier,n表示数字num
char Terminals[]={'+','-','*','/','(',')','i','n','$'};
char UnTerminals[]={'E','M','T','N','F'};
string Map[5][9]={                                         //手动构造LL(1)语法预测分析表  
     "","","","","TM","","TM","TM","",
     "+TM","-TM","","","","e","","","e",
     "","","","","FN","","FN","FN","",
     "e","e","*FN","/FN","","e","","","e",
     "","","","","(E)","","i","n",""
     };
// 保存输入的文法串
char input[30];
int len;
void getInput(void)
{
    printf("Please input syntax string in here:");
    scanf("%s",input);
    // solve its len
    for(len=0;input[len]!='\0';len++);
    // dollar符号添加到分析串最后
    input[len]='$';
    input[len+1]='\0';
    len++;
    // 初始化符号栈
    Stack.push('$');
    Stack.push('E');
}
bool checkID(char ch)
{
    if(isalpha(ch))
        return true;
    return false;
}
bool checkNum(char ch)
{
    if(isdigit(ch))
        return true;
    return false;
}
void outputCurStack(void)
{
    char curr[30];
    int i=0,j=0,number=Stack.size();
    cout<<"\t";
    for(i=0;i<number;i++)
    {
        curr[i]=Stack.top();
        Stack.pop();
    }
    for(i=number-1;i>=0;i--)
    {
        switch(curr[i])
        {
            case 'M':
                cout<<"E'";
                break;
            case 'N':
                cout<<"T'";
                break;
            case 'i':
                cout<<"id";
                j++;
                break;
            case 'n':
                cout<<"num";
                j+=2;
                break;
            default:
                cout<<curr[i];
                break;
        }
        Stack.push(curr[i]);
    }
    for(i=0;i<8-j-number;i++)
        cout<<" ";
}
void outputCurBuffer(int ip)
{
    int i,j;
    cout<<"\t";
    for(i=ip;input[i]!='$';i++)
        cout<<input[i];
    cout<<"$";
    for(j=0;j<8-i+ip;j++)
        cout<<" ";
}
int getTerminalSeq(char ch)  //返回终结符在终结符表中的下标 
{
    int i;
    for(i=0;i<9;i++)
       if(ch==Terminals[i])
          return i;
    return -1;
}
int getUnterminalSeq(char ch)  //返回非终结符在非终结符表中的下标 
{
    int i;
    for(i=0;i<5;i++)
       if(ch==UnTerminals[i])
          return i;
    return -1;
}
bool checkTeminal(char ch)  //判断字符是否为终结符 
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='i'||ch=='n'||ch=='$')
       return true;
    else
       return false;    
}
bool checkUnterminal(char ch)  //判断字符是否为非终结符 
{
    if (ch=='E'||ch=='M'||ch=='T'||ch=='N'||ch=='F')
       return true;
    else
       return false;
}
void analyzer(void)
{
    int i,j,n,m;
    int step=0,ip=0,length=0;
    int tag1=0,tag2=0;
    char X,a,c,b[20],st[20];
    cout<<"步骤\t"<<"\t\t栈\t\t"<<"输入\t"<<"\t输出\t\n";
    do
    {
        step++;
        printf("The %d step:\t",step);
        X=Stack.top();
        a=input[ip];
        for(i=0;i<=20;i++)
            b[i]='\0';
        if(a=='+'||a=='-'||a=='*'||a=='/'||a=='('||a==')'||a=='$')
            length=1;
        else
        {
            /* process id and num situation */
            j=ip;
            length=0;
            if(checkID(a))
                tag1=tag2=1;
            if(checkNum(a))
                tag1=tag2=2;
            j++;
            c=a;
            do 
            {
                length++;
                b[length-1]=c;
                c=input[j];
                if(checkID(c))
                    tag2=1;
                else if(checkNum(c))
                    tag2=2;
                else
                    tag2=0;
                j++;
                } while(tag1==tag2);
            if(tag1==1)
                a='i';
            if(tag1==2)
                a='n';    
            }
        outputCurStack();
        outputCurBuffer(ip);
        if(checkTeminal(X))
        {
            if(X==a)
            {
                if(X=='$')
                    cout<"\tAccepted\t";
                Stack.pop();
                ip+=length;
            }
            else
            {
                cout<<"ERROR!";
                cout<<"\n";
                return;
            }
        }
        else                        //栈顶符号是非终结符 
        {
            n=getUnterminalSeq(X);
            m=getTerminalSeq(a);
            if(Map[n][m]!="")
            {
                Stack.pop();            //从栈顶弹出X
                if(Map[n][m]!="e")    //如果产生式不是ε，将产生式逆序压入栈中 
                {
                   for(i=0;Map[n][m][i]!='\0';i++)
                      st[i]=Map[n][m][i];
                   for(i=i-1;i>=0;i--)
                      Stack.push(st[i]);
                   }
                switch(X)
                {
                   case 'M':
                      cout<<"\tE'→";
                      break;
                   case 'N':
                      cout<<"\tT'→";
                      break;         
                   default:
                      cout<<"\t"<<X<<"→";
                      break;
                      }
                if(Map[n][m]=="e")
                   cout<<"ε\t"; 
                else if(Map[n][m]=="i")
                   cout<<"id";
                else if(Map[n][m]=="n")
                   cout<<"num";
                else
                   cout<<Map[n][m]<<"\t";
                }
            else
            {
                cout<<"\t错误!\t\n";
                return;
                }
            }
        cout<<"\n";        
    } while(X!='$');
    
}
int main(void)
{
    getInput();
    analyzer();
    system("pause");
    return 0;
}