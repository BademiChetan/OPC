#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n,i,j,t;
	unsigned long int k,ans;
	cin>>t;
    for(i=0;i<t;++i)
	{
		cin>>n;
		cin>>k;
		n=n%k;
		ans = (int)pow(2,pow((double)n,2));
		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}





