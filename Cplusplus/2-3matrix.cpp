#include<iostream>
using namespace std;

class Matrix
{
	private:
		int lines,rows;
	public:
		/*
		@Based on some basic src.
		@For convenience，all func we just define
			within the inner class.
			But,
				many times u need to do it out of class.
				Use Matrix::input()...this type
					Because those inner defined funcs are inline. 
		*/ 
		int **a;//二维数组指针
		void input()
		//cin initialize,we set it like inline func
		{
			int i,j;
			cout<<"Pls input ur matrix element which is of"<<\
				lines<<"*"<<rows<<endl;
			for(i=0;i<lines;i++)
				for(j=0;j<rows;j++)
					cin>>a[i][j];
		}
		void output()
		//output inline func
		{
			cout<<"Here's ur output"<<endl;
			for(int i=0;i<lines;i++)
			{
				for(int j=0;j<rows;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
		}
		
		void sum(Matrix &a,Matrix &b)//矩阵相加 
       {
           int i,j;
           for(i=0;i<lines;i++)
           {
                for(j=0;j<rows;j++)
                  {
                       this->a[i][j]=a.a[i][j]+b.a[i][j];
                  }
           }
       }
      
      	void sub(Matrix &a,Matrix &b)//矩阵相减 
       {
           int i,j;
           for(i=0;i<lines;i++)
           {
                for(j=0;j<rows;j++)
                  {
                       this->a[i][j]=a.a[i][j]-b.a[i][j];
                  }
           }
       }
       
       Matrix()//wucangouzaohanshu 
	   {
          cout<<"输入矩阵的行数和列数："<<endl;
          cin>>lines>>rows;
                               
          a=new int*[lines];
          for(int i=0;i<lines;i++)
             a[i]=new int[rows];               
      }
      
       Matrix(int x,int y) //构造函数申请，参数为行和列 
      {
          lines=x;
          rows=y;
          
          a=new int*[lines];//二维数组申请空间 
          for(int i=0;i<lines;i++)
             a[i]=new int[rows];               
      }
      
       Matrix(Matrix &A)//拷贝构造函数 ,复制 
      {
          a=new int*[A.lines];
          for(int i=0;i<A.lines;i++)
             a[i]=new int[A.rows];       
          lines=A.lines;
          rows=A.rows;        
      } 
    
    	~Matrix()
      {
      	for(int i=0;i<lines;i++)
         {
            delete [] a[i];
            delete [] a;
         }
	  }
		
		
};
int main()
{
	  int m,n;
      cout<<"输入俩矩阵信息"<<endl;
      Matrix A1;
      Matrix A2=A1;//拷贝构造函数 
      Matrix A3=A1;
      
      A1.input();
      A2.input();
      
      cout<<"A1矩阵为："<<endl;
      A1.output();
      
      cout<<"A2矩阵为："<<endl;
      A2.output();
      
      A3.sum(A1,A2);
      cout<<"两矩阵相加为："<<endl;
      A3.output();
      
      A3.sub(A1,A2);
      cout<<"两矩阵相减为："<<endl;
      A3.output();	
      
      Matrix *pA1,*pA2,*pA3;
      pA1=new Matrix;
      pA2=new Matrix;
      pA3=new Matrix;
      
      cout<<"输入俩矩阵信息"<<endl; 
      pA1->input();
      pA2->input();
      
      pA3->sum(*pA1,*pA2);
      cout<<"加后得到"<<endl;
      pA3->output();
      
      pA3->sub(*pA1,*pA2);
      cout<<"简后得到"<<endl;
      pA3->output(); 
      
      delete pA1,pA2,pA3;
      return 0;
} 
