#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=0,temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			sum+=temp;
		}
		temp=0;
		int x;
		if(n%2==1)
		{
			x=(n-1)/2;
			temp=x*(x+1);
		}
		else
		{
			x=(n-2)/2;
			temp=x*(x+1);
			temp+=n/2;
		}
		sum=sum-temp;
		if(sum%2==1)
			cout<<"WIN"<<endl;
		else
			cout<<"LOSE"<<endl;
	}
}