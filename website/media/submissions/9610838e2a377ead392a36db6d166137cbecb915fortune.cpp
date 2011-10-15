#include<iostream>
using namespace std;

int main()
{
	int n,k,t,i;
	cin>>t;
	int m[t];
	i=0;
	while(i<t)
	{
		m[i]=2;
		cin>>n>>k;
		int j=1;
		while(j<=n)
		{
			m[i]=m[i]*m[i];
			j++;
		}
		i++;
	}
	i=0;
	while(i<t)
		cout<<m[i++]<<endl;
	return 0;
}
		
	


