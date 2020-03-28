/*
5.1 虚函数 针对题目3的 “形状 ”类，编写C++程序完成以下功能：
 （1） 将【形状】 中的基类计算面积的方法定义为虚函数，比较与【形状（A）】程 序的差异； 
 （2） 将【形状】中的基类定义为抽象类，比较与【形状（A）】程序的差异。 
*/

#include <iostream>
const double PI=3.14;
using namespace std;

class shape
{
	public:
		virtual float area()
		{
			
		}
		shape()
		{
			cout<<"构造一个shape父类"<<endl;
		}
		
		~shape(){
			cout<<"析构一个shape父类"<<endl; 
		}
		
 };
 
 class rectangle:public shape//extends shape
 {
 	private:
 		float length,width;
 	public:
 		rectangle(float a,float b)
 		{
 			//带参数的构造函数,this是显式指针 
 			cout<<"带参数构造长方形"<<endl;
 			this->length=a;
 			this->width=b;
		 }
		rectangle()
		{
			cout<<"构造一个长方形"<<endl;
		}
		
		void set(float a,float b)
		{
			//set方法
			this->length=a;
			this->width=b; 
		}
		
		~rectangle(){
			cout<<"析构长方形"<<endl; 
		}
		
		float area()
		{
			return length*width;
		}
  }; 
  
  class circle:public shape
  {
  	private:
  		float radius;
  		float x,y;
  	public:
  		circle()
  		{
  			cout<<"构造一个圆"<<endl;
		  }
		~circle()
		{
			cout<<"析构一个圆"<<endl;
		}
		circle(float radius,float x,float y)
		{
			cout<<"带参构造一个圆"<<endl;
			this->radius=radius;
			this->x=x;
			this->y=y;
		}
		void set(float radius,float x,float y)
		{
			this->radius=radius;
			this->x=x;
			this->y=y;
		}
		
		float area()
		{
			return PI*radius*radius;
		}
  };
  
  class square:public rectangle
  {
  	friend class circle; //test
  	private:
         float bianchang;
    public:
    	 square(float a):rectangle(a,a)
         {
         	 cout<<"构造带参数正方形"<<endl;
             bianchang=a;
         }
         ~square()
         {
         	cout<<"析构正方形"<<endl;
		 }
  };
  int main()
{
     float a,b;
     cout<<"请输入矩形的长和宽:"<<endl;
     cin>>a>>b;
     rectangle M(a,b);
     cout<<"矩形的面积为："<<M.area()<<endl; 
     
     float r,x,y;
     cout<<"请输入圆的半径,x,y position："<<endl;
     cin>>r>>x>>y;
     circle C(r,x,y);
     cout<<"圆的面积为："<<C.area()<<endl;
     
     float c;
     cout<<"请输入正方形边长："<<endl;
     cin>>c;
     square Z(c);
     cout<<"正方形的面积为："<<Z.area()<<endl;
     
     system("pause");
     return 0; 
}
