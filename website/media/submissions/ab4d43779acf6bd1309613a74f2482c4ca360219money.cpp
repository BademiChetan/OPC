#include <iostream>
#include <math.h>
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
		
		int temp=int(pow(2.0,floor(log( (log(K[i])*1.0/log(2.0)) )/log(2.0))));
		int temp2=N[i]%temp;
		if(temp2==0 && N[i]!=0) temp2=temp;
	
			int t=2;
			for(int j=0;j<temp2;j++)
			{
				t=(t*t)%K[i];
			}
			cout<<t<<endl;
		
	}
	delete []N;
	delete []K;    
	return 0;
}