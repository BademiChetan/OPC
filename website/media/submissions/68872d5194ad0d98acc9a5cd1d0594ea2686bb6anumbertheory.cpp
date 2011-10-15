#include<iostream>
using namespace std;
int main()
{
	int a[100],n,t;
	int count;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[i]%2!=0)
				count++;
		}
		if(count%2==0)
			cout<<"LOSE\n";
		else
			cout<<"WIN\n";
	}
	return 0;
}



