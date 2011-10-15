//In the name of Allah
//
//
#include <iostream>
using namespace std;
int t,n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (;t;t--)
	{
		cin>>n;
		int now=0;
		for (int i=0;i<n;i++)
		{
			now-=i;
			int a;
			cin>>a;
			now+=a;
		}
		cout<<(now%2==0?"LOSE":"WIN")<<endl;
	}
	return 0;
}
