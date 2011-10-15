#include<iostream>
using namespace std;

int main()
{
	int n,k,t;
	cin>>t;
	int m[t];
	for(int i=0;i<t;i++)
	{
		m[i]=2;
		cin>>n>>k;
		for(int j=1;j<=n;j++)
			m[i]=m[i]*m[i];
	
	}
	for(int i=0;i<t;i++)
		cout<<m[i]<<endl;
	return 0;
}
		
	


