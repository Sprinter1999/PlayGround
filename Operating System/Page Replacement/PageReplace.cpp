#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	int Frame_size=5;
	cout<<"Firstly we simulate FIFO method,please input the initial Frames size:"<<endl;
	cin>>Frame_size;
	vector<int> q(Frame_size,-1);
	int Reference_string[]={ 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
	int N=sizeof(Reference_string)/sizeof(Reference_string[0]);
	int page_fault_times=0;
	int victim=0;
	for(int i=0;i<N;i++)
	{
		int temp=Reference_string[i];
		bool flag=false;//means string[i] not in QUEUE
		for(int j=0;j<Frame_size;j++)
		{
			if(q[j]==temp)
			{
				flag=true;
				break;
			}
			if(q[j]==-1)
				break;
		}
		if(flag)
		{
			cout<<"TURN:"<<i<<" ,No page fault"<<endl;
		}
		else
		{
			q[victim]=temp;
			victim=(victim+1)%Frame_size;
			cout<<"TURN:"<<i<<" ,page fault! ";
			cout<<"FRMAMES:"<<q[0]<<" "<<q[1]<<" "<<q[2]<<" "<<q[3]<<" "<<q[4]<<endl;
			page_fault_times++; 
			
		}
	}
	cout<<"Sum of page fault is "<<page_fault_times<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"Then we move to LRU method"<<endl;
	//7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1
	vector<int> qq(Frame_size,-1);
	victim=0;
	page_fault_times=0;
	N=sizeof(Reference_string)/sizeof(Reference_string[0]);
	for(int i=0;i<N;i++)
	{
		int temp=Reference_string[i];
		bool flag=false;//means string[i] not in Frames
		for(int j=0;j<Frame_size;j++)
		{
			if(qq[j]==temp)
			{
				flag=true;
				break;
			}
			if(qq[j]==-1)
				break;
		}
		if(flag)
		{
			cout<<"TURN:"<<i<<", "<<temp<<" ,No page fault"<<endl;
		}
		else
		{
			//stands for we need to refer to REFERENCE_STRING to find a victim in FRAMES
			page_fault_times++;
			int pointer=i;
			int counter=0;
			bool matcher[Frame_size];
			for(int ite=0;ite<Frame_size;ite++)
				matcher[ite]=false;
			while(pointer>=0&&counter<=Frame_size-1)
			{
				if(pointer<=0) break;
				pointer--;
				int comp=Reference_string[pointer];
				for(int it=0;it<Frame_size;it++)
				{
					if(comp==qq[it])
					{
						matcher[it]=true;
						counter++;
						break;
					}
				}
			}
//			cout<<"matcher:"<<matcher[0]<<matcher[1]<<matcher[2]<<matcher[3]<<matcher[4]<<endl;
			for(int it=0;it<Frame_size;it++)
			{
				if(matcher[it]==false)
				{
					qq[it]=Reference_string[i];
					break;
				}
			}
			cout<<"TURN:"<<i<<", "<<temp<<" ,page fault! ";
			cout<<"FRMAMES:"<<qq[0]<<" "<<qq[1]<<" "<<qq[2]<<" "<<qq[3]<<" "<<qq[4]<<endl;
			
		}
	}
	cout<<"Sum of page fault is "<<page_fault_times<<endl;
} 
