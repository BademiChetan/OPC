#include<iostream>
using namespace std;

int main()
{
	int t,n,o,e;
	int a[100],no,ne;
	cin>>t;
	while(t--)
	{
		cin>>n;
		no=ne=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
				ne++;
			else
				no++;
		}
		if(n==3 || n==4)
		{
			e=1;
			o=n-e;
		}
		else
		{
			e=0;
			o=n-e;
		}
		for(;e<=n;o-=2,e+=2)
		{
			if(e==no && o==ne)
			{
				cout<<"WIN"<<endl;
				break;
			}
		}
		if(e>n)
			cout<<"LOSE"<<endl;
	}
}	
				
	
