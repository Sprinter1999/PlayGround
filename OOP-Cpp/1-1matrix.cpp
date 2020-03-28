// ConsoleApplication7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
/***********************
Practica1:C++基础知识实验
编写C++程序完成“矩阵”以下功能：
（1） 假定矩阵大小为 4×5（整型）；
（2） 矩阵空间采用 new 动态申请，保存在指针中；
（3） 定义矩阵初始化函数，可以从 cin 中输入矩阵元素；
（4） 定义矩阵输出函数，将矩阵格式化输出到 cout；
（5） 定义矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵中；
（6） 定义矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵中；
（7） 动态申请三个矩阵：A1、A2、A3；
（8） 初始化 A1、A2；
（9） 计算并输出 A3 = A1 加 A2，A3 = A1 减 A2；
（10） 释放矩阵空间

  Scripted by：Xuefen in Bupt
***********************/
/*要求的算法：*/
#include<iostream>
using namespace std;

class matrix
{
public:
	int a[4][5];
	void input()
	{
		int i, j;

		cout << "请输入矩阵A1(4*5):" << endl;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cin >> a[i][j];
			}
		}
	}

	void output()
	{
		int i, j;

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}

	void sum(matrix &a, matrix &b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				this->a[i][j] = a.a[i][j] + b.a[i][j];
			}
		}
	}

	void sub(matrix &a, matrix &b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				this->a[i][j] = a.a[i][j] - b.a[i][j];
			}
		}
	}

};

int main()
{
	matrix *A1, *A2, *A3;
	A1 = new matrix;
	A2 = new matrix;
	A3 = new matrix;

	A1->input();
	A2->input();

	cout << "A1矩阵为：" << endl;
	A1->output();

	cout << "A2矩阵为：" << endl;
	A2->output();

	A3->sum(*A1, *A2);
	cout << "两矩阵相加为：" << endl;
	A3->output();

	A3->sub(*A1, *A2);
	cout << "两矩阵相减为：" << endl;
	A3->output();

	delete A1;
	delete A2;
	delete A3;
	return 0;
}
















/********************************************************
Traditional solution without "New":
class matrix
{
public:
	//数据元素 
	int a[4][5];
	//成员函数 
	void input()
	{
		int i, j;
		//cout << "Please input matrix(4*5) in line here:" << endl;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 5; j++)
				cin >> a[i][j];
	}

	void output()
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	void sum(matrix a, matrix b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 5; j++)
				this->a[i][j] = a.a[i][j] + b.a[i][j];
	}

	void sub(matrix a, matrix b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 5; j++)
				this->a[i][j] = a.a[i][j] - b.a[i][j];
	}
};



int main()
{
	matrix A1, A2;
	cout << "Please input A1 matrix （4*5-scale） info in line here:\n";
	A1.input();
	cout << "Please input A2 matrix （4*5-scale）info in line here:\n";
	A2.input();
	//Display of A1 A2 is of no meaning

	cout << endl;
	cout << "Sum of A1 and A2 is:\n";
	matrix A3;
	A3.sum(A1, A2);
	A3.output();
	cout << "Substract of A1 and A2 is:\n";
	A3.sub(A1, A2);
	A3.output();

	return 0;
}
********************************************************/

