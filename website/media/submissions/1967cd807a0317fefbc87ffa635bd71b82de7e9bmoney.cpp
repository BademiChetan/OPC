#include <iostream>
using namespace std;
int main()
{
	int T;
	long int *N=new long int[T];
	long int* K=new long int[T];
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N[i]>>K[i];	
	}
	for(int i=0;i<T;i++)
	{
		long int t=2;
		for(long int j=1;j<=N[i];j++)
		{
			t=(t*t)%K[i];	
		}
		cout<<t<<endl;
	}
	return 0;
}