#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int cas,t,k;
	long long int ans;
	cin>>cas;
	for(int i=0;i<cas;i++)
	{
		cin>>t>>k;
		ans=pow(2,2*t);
		cout<<ans<<endl;
	}
return 0;
}

