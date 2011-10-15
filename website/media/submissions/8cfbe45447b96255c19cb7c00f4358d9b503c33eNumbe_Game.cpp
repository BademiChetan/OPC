#include<iostream>
using namespace std;
int main(void)
{
	int t,a[100];
	cin>>t;
	for(;t>0;t--)
	{
		int n,i;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(i=1;i<n;i++)
		{
			a[i+1]=(a[i]+a[i+1]-i);
		}
		if(a[i]%2==0)
		cout<<"LOSE"<<endl;
		else cout<<"WIN"<<endl;
	}
	return 0;
}
		
		
