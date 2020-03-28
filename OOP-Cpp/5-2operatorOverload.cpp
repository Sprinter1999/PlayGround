/*
5.2 对Point类重载＋＋和――运算符     编写C++程序完成以下功能：
 （1） Point 类的属性包括点的坐标（x，y）； 
 （2） 实现 Point 类重载＋＋和――运算符： ? ++p，--p，p++，p--；注意他们是不一样的！！！ 
											 ? ＋＋和――分别表示 x，y 增加或减少 1。 
*/ 

//以后有空再细看吧
 
#include <iostream>
using namespace std;

class point
{
      private:
         int x;
         int y;
      public:
         void setpoint(int a,int b)
         {
              x=a;
              y=b;
         }
         
         void output()
         {
              cout<<"("<<x<<","<<y<<")"<<endl;
         }
         
         point()
         {}//构造函数 
         ~point()
         {}//析构函数
         
         point operator ++ (int)
         {
               point r;
               r.x=x+1;
               r.y=y+1;
               return r;
         }
         
         point operator --(int)
         {
               point r;
               r.x=x-1;
               r.y=y-1;
               return r;
         }
         
         point operator ++()
         {
               point r;
               x=x+1;
               y=y+1;
               r.x=x;
               r.y=y;
               return r;
         }
         
         point operator --()
         {
               point r;
               x=x-1;
               y=y-1;
               r.x=x;
               r.y=y;
               return r;
         }         
} ;
         
int main()
{
      point o,t;
      int m,n;
      cout<<"请输入点的坐标："<<endl;
      cin>>m>>n;
      o.setpoint(m,n);
      while(1){
      int choose;
      cout<<"请选择运算:1.p++ 2.p-- 3.++p 4.--p 0.exit()"<<endl;
      cin>>choose;
      
      if(choose==1)
      {
           t=(o++);
           cout<<"运算后的坐标为："<<endl;
           t.output();
      }
      if(choose==2)
      {
           t=(o--);
           cout<<"运算后的坐标为："<<endl;
           t.output();  
      }
      if(choose==3)
      {
           t=(++o);
           cout<<"运算后的坐标为："<<endl;
           t.output();       
      }
      if(choose==4)
      {
           t=(--o);
           cout<<"运算后的坐标为："<<endl;
           t.output();                   
      }  
      if(choose==0)
      	break;
  }
      system("pause");
      return 0;
} 
