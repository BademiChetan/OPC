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
		sum=sum-(n*(n-1)/2);
		if(sum%2==1)
			cout<<"WIN"<<endl;
		else
			cout<<"LOSE"<<endl;
	}
}