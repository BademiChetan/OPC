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
		try
		{
	    if(n==0||k==0)
			throw 2;
		n=n%k;
		
		}catch (int e)
		{
			}
		ans = (int)pow(2,pow(2,(double)n));

		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}





