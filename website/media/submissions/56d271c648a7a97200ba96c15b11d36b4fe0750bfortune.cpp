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
		sum=2;
		for(i=0;i<N[j];i++)
		{
			money[j]=pow(sum,2);
			sum=money[j];
		}
	}
	for(i=0;i<T;i++)
	cout<<endl<<money[i]%K[i];
}

