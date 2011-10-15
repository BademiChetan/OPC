#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n,i,j,t;
    long long int k,ans;
	cin>>t;
    for(i=0;i<t;++i)
	{
		cin>>n>>k;
		ans=(int ) (pow(2,pow(2, (double) n)));
		ans=ans%k;
		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}





