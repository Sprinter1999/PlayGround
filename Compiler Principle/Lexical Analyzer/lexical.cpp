#include <iostream>        
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//C语言保留字
string keyword[32]={"auto","break","case","char","const",            
                  "continue","default","do","double","else","extern",
                  "enum","float","for","goto","if","int","long","return",
                  "register","static","short","signed","unsigned",
                  "struct","switch","sizeof","typedef","union",
                  "volatile","void","while"};
//行列指针
int column=0,row=1;
//character字符个数，word单词个数
int character=0,word=0; 
//从example.txt中读入测试程序
ifstream infile("example.txt",ios::in);
//每一次处理的字符
char c;


//检查是否是C语言关键字
int find_keyword(string word)                    
{
    for(int i=0;i<32;i++)
       if(keyword[i].compare(word)==0)//string类型的compare方法，如果相等该方法返回1
          return 1;
    
    return 0;
}


void choice()
{
    while(c=='\n'||c==' '||c=='\t')  //不计空白符 
    {
       //遇到回车，则跳到下一行，并且get到下一个字符，col++
       if (c=='\n')
       {
          row++;
          column=0;          
       }
       c=infile.get();
       column++;
       }
    return;
    }


void get()                   //全局方法，直接读取下一个字符
{
    character++;
    c=infile.get();
    column++;
    return;
}


int parser()
{
    string once="";//单次记号流
    
    if(infile.fail())
        cout<<"请先创建example.txt并向其中输入示例程序"<<endl;
    else
    {
        ofstream outfile("out.txt");
        outfile<<setw(10)<<"Expression"<<setw(30)<<"Mark"<<setw(30)<<"Type"<<endl; 

        c=infile.get();
        column++;
        // Automa
        while(c!=EOF)
        {
            switch(c){  
            //identifier                              
            case 'A'...'Z':
            case 'a'...'z':
            case '_':
                word++;
                while(isalpha(c)||isdigit(c)||c=='_')
                {
                   once+=c; //继续往后识别，once连缀上c，直到没有遇见字母、数字or下划线为止
                   get();   //往后读取一个字符
                }
                //遇到构成标识符的不合法字符，提示错误
                if(c=='@'||c=='?'||c=='$'||c=='#')
                {
                    int tag=column; 
                    //一直往后读下去
                    while(isalpha(c)||isdigit(c)||c=='_'||c=='@'||c=='?'||c=='$'||c=='#')                                   
                    {
                       once+=c;
                       get();
                    }
                    //识别完成，记录once
                    outfile<<setw(10)<<once<<setw(30)<<"ERROR"<<setw(30)<<"错误在第"<<row<<"行第"<<tag<<"列"<<endl;
                    once="";//复原once
                    break;
                }
                //检查是否是关键字
                if(find_keyword(once))
                {
                    outfile<<setw(10)<<once<<setw(30)<<once<<setw(30)<<"关键字"<<endl;
                    once="";
                }
                //没有错，又不是关键字，那就是标识符了
                else
                {
                    outfile<<setw(10)<<once<<setw(30)<<"id"<<setw(30)<<"标识符"<<endl;
                    once="";
                } 
                break;

            //数字开头为常数
            case '0'...'9':
                word++;
                //先读取（digit）+ 
                while(isdigit(c))
                {
                   once+=c;
                   get();
                }
                //10.7888 scenario
                if(c=='.')
                {
                	once+=c;
                	get();
                	while(isdigit(c))
                	{
                		once+=c;
                		get();
					}
				}
				//7E+19 scenario
                if(c=='E'||c=='e')
				{
					once+=c;
					get();
					while(isdigit(c)||c=='+'||c=='-')
					{
						once+=c;
						get();
					}
				 } 
                //常数中出现了字母，报错
                if(isalpha(c))
                {
                   int tag=column;
                   while(isalpha(c)||c=='_'||isdigit(c)||c=='@'||c=='?'||c=='$'||c=='#')                                   
                   {
                      once+=c;
                      get();
                   }
                   outfile<<setw(10)<<once<<setw(30)<<"ERROR"<<setw(30)<<"错误在第"<<row<<"行第"<<tag<<"列"<<endl;
                   once="";
                   break;                   
                }
                //否则正常输出
                outfile<<setw(10)<<once<<setw(30)<<"num"<<setw(30)<<"无符号数"<<endl;
                once="";
                break;
            case'>':
                get();
                if(c=='=')
                   outfile<<setw(10)<<">="<<setw(30)<<"relop"<<setw(30)<<"关系运算符"<<endl;
                else if(c=='>')
                   outfile<<setw(10)<<">>"<<setw(30)<<"bit_op"<<setw(30)<<"位运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<">"<<setw(30)<<"relop"<<setw(30)<<"关系运算符"<<endl;                
                   break;
                }
                get();
                break;
            case'<':
                get();
                if(c=='=')
                   outfile<<setw(10)<<"<="<<setw(30)<<"relop"<<setw(30)<<"关系运算符"<<endl;
                else if(c=='<')
                   outfile<<setw(10)<<"<<"<<setw(30)<<"bit_op"<<setw(30)<<"位运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"<"<<setw(30)<<"relop"<<setw(30)<<"关系运算符"<<endl;                
                   break;
                }
                get();
                break;
            case'=':
                get();
                if(c=='=')
                   outfile<<setw(10)<<"=="<<setw(30)<<"relop"<<setw(30)<<"关系运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"="<<setw(30)<<"assign_op"<<setw(30)<<"赋值符"<<endl;                
                   break;
                }
                get();
                break;
            case'!':
                get();
                if(c=='=')
                   outfile<<setw(10)<<"!="<<setw(30)<<"relop"<<setw(30)<<"关系运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"!"<<setw(30)<<"logic_op"<<setw(30)<<"逻辑运算符"<<endl;                
                   break;
                   }
                get();
                break;
            case'|':
                get();
                if(c=='|')
                   outfile<<setw(10)<<"||"<<setw(30)<<"relop"<<setw(30)<<"逻辑运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"|"<<setw(30)<<"logic_op"<<setw(30)<<"位运算符"<<endl;                
                   break;
                }
                get();
                break;
            case'&':
                get();
                if(c=='&')
                   outfile<<setw(10)<<"&&"<<setw(30)<<"relop"<<setw(30)<<"逻辑运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"&"<<setw(30)<<"logic_op"<<setw(30)<<"位运算符或取址符"<<endl;                
                   break;
                }
                get();
                break;
            case'+':
                get();
                if(c=='+')
                   outfile<<setw(10)<<"++"<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;
                else if(c=='=')
                   outfile<<setw(10)<<"+="<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"+"<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;                
                   break;
                }
                get();
                break;
            case'-':
                get();
                if(c=='-')
                   outfile<<setw(10)<<"--"<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;
                else if(c=='=')
                   outfile<<setw(10)<<"-="<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"-"<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;                
                   break;
                }
                get();
                break;
            case'*':
                get();
                if(c=='=')
                   outfile<<setw(10)<<"*="<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;
                else
                {
                   outfile<<setw(10)<<"*"<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;                
                   break;
                   }
                get();
                break;

            case '\"':
                once+=c;
                get();
                while(c!='\"')
                {
                   once+=c;
                   get();
                   if(c==' '||c=='\t')
                      character--;
                }
                once+='\"';
                outfile<<setw(10)<<once<<setw(30)<<"literal"<<setw(30)<<"字符串"<<endl;
                once="";
                get();
                break;
            case'/':
                once+=c;
                get();
                if(c=='=')
                   outfile<<setw(10)<<"/="<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;
                else if(c=='/')
                {
                   once+=c;
                   get();
                   while(c!='\n'&&c!=EOF)
                   {
                       once+=c;
                       get();
                   }
                   character--;
                   outfile<<setw(10)<<once<<setw(30)<<"annotation"<<setw(30)<<"注释"<<endl;
                   } 
                else if(c=='*')
                {
                   once+=c;
                   get();
                   char tag=c;
                   while(tag!='*'&&c!='/'&&c!=EOF) 
                   {
                       once+=c;
                       tag=c;
                       choice();
                       get();
                   }
                   once+=c;
                   outfile<<setw(10)<<once<<setw(30)<<"annotation"<<setw(30)<<"注释"<<endl;
                 } 
                else
                {
                   outfile<<setw(10)<<"/"<<setw(30)<<"alg_op"<<setw(30)<<"运算符"<<endl;                
                   once="";
                   break;
                }
                once="";
                get();
                break;
            case ' ':
            case '\n':
            case EOF:
                break;
            default:
                outfile<<setw(10)<<c<<setw(30)<<c<<setw(30)<<"符号"<<endl;
                get();
                break;     
            }
            choice(); 
            }
        outfile<<"语句行数："<<row<<endl;
        outfile<<"单词个数："<<word<<endl;
        outfile<<"字符个数："<<character<<endl;
        infile.close();
        outfile.close();
        return 1;
        }
        
    infile.close();
    return 0;
    }

int main()
{
    int flag;
    
    flag=parser();
    
    if(flag==1)
    {
       cout<<"词法分析源程序详见example.txt"<<endl;
       cout<<"词法分析结果及错误分析详见out.txt"<<endl;                 //输出结果 
       cout<<"语句行数："<<row<<endl;
       cout<<"单词个数："<<word<<endl;
       cout<<"字符个数："<<character<<endl;
       }
    
    system("pause");
    return 0;
    }
