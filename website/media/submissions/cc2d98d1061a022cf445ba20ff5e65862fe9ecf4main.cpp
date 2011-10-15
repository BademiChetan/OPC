#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n,i,num,j,t;
	unsigned long int k,ans=2;
	cin>>t;
    for(i=0;i<t;++i)
	{
		ans=2;
		cin>>n;
		cin>>k;
		for(j=1;j<=n;++j)
			ans=pow((double) ans,2);
		ans=ans%k;
		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}





