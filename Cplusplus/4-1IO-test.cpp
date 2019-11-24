/*
	@作业要求：
	 编写 C++程序完成猜价格游戏的以下功能：
	（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000 的整数）；
	（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出
	相应的提示；
	（3） 直到猜对为止，并给出提示。
	（提示及要求：1，要求使用 C++的输入输出方式（cin, cout），不能使用 C 语
	言的 printf 等；2，注意检查输入的合法性）
*/ 
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
    
    int price=rand()%1000+1;
    //@refer to
	//https://blog.csdn.net/cmm0401/article/details/54599083
	int cprice;
	int judge=0;
	
	cout<<"请输入价格(1-1000的整数):"<<endl;
	cin>>cprice;
	
	while(judge!=1)
	{
		if(cprice==price)
		{
			judge=1;
			cout<<"恭喜，您输入的价格正确"<<endl; 
		}
		if(cprice>price)
		{
			judge=0;
			cout<<"您输入的价格比正确价格高,请重新输入："<<endl;
			cin>>cprice;
		}
		if(cprice<price)
		{
			judge=0;
			cout<<"您输入的价格比正确价格低，请重新输入："<<endl;
			cin>>cprice; 
		}
	}
	
	system("pause");
	return 0;
}
