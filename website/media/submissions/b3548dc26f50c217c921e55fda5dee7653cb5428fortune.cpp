#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

main()
{
	long int N[1000],money[1000],i,K[1000],j,sum=2,T;
	cin>>T;
	for(i=0;i<T;i++)
	cin>>N[i]>>K[i];
	for(j=0;j<=T;j++)
	{
		sum=pow(2,N[j]);
		money[j]=pow(2,sum);
		
	}
	for(i=0;i<T;i++)
	cout<<endl<<money[i]%K[i];
}

