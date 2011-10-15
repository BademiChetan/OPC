#include<iostream>
using namespace std;

int main()
{
	int t,n,sum,i,j,k,final;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		sum=0;
		for(j=0;j<n;j++)
		{
			cin>>k;
			sum+=k;
		}
		final=sum-((n-1)*n)/2;
		if(final%2==0)
			cout<<"LOSE"<<endl;
		else
			cout<<"WIN"<<endl;
	}
	return 0;
}
