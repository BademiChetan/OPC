#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;

	int **test=new int*[T];
	for(int i=0;i<T;i++)
	{
		test[i]=new int[2];
	}
	for(int i=0;i<T;i++)
	{
		cin>>test[i][0]>>test[i][1];
	}
	for(int i=0;i<T;i++)
	{
		if(test[i][0]>test[i][1])
		{
			int temp=test[i][0];
			test[i][0]=test[i][1];
			test[i][1]=temp;
		}
		if(test[i][1]%2==0)
		{
			if(test[i][1]==test[i][0])
			{
				cout<<"0"<<endl;
			}
			else
			{
				cout<<test[i][1]+test[i][0]<<endl;
			}
		}
		else
		{
			if(test[i][1]==test[i][0])
			{
				cout<<"0"<<endl;
				continue;
				
			}
			if(test[i][1]-test[i][0]==1)
			{
				cout<<"1"<<endl;
				
			}
			else
			{
				if(test[i][0]%2==0)
				{
					cout<<test[i][0]+test[i][1]<<endl;
				}
				else
				{
					cout<<test[i][0]+test[i][1]-2<<endl;
				}
			}
		}
			
	}
	for(int i=0;i<T;i++)
	{
		delete []test[i];
	}
	delete []test;
	return 0;
}