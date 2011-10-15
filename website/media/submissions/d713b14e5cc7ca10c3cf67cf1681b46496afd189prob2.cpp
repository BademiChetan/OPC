#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	//freopen("prob2.in","r",stdin);
	//freopen("prob2.out","w",stdout);
	int t,n,k;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		int ans=0;
		cin>>n;
		for (int j=0;j<n;j++)
		{
			cin>>k;
			ans+=(k-j);
		}
		string str=(ans&1)?"WIN":"LOSE";
		cout<<str<<endl;
	}
	return 0;
} 
