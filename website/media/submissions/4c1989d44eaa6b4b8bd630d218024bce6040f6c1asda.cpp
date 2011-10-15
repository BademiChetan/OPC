#include<iostream>
using namespace std;
int l;
long long int abcd(long long int N,long long int K)
{
	if(N<l)
		return 1<<N ;
	else
		if(N & 1)
		{
			return (abcd(N/2,K)*abcd(N/2,K))%K;
		}
		else
		{
			return ((abcd(N/2,K)*abcd((N/2)+1,K)))%K;
		}
}
int getl(long long int N)
{
	for(l=0;N!=0;l++)
	{
		N=N>>1;
	}
}


long long int fun(long long int N, long long int K)
{
	long long int prod=2,i;
	for( i=0;i<N;i++){
		prod=(prod*prod)%K;
		}
	return prod;
}
	

int main()
{
	int t;
	cin>>t;
	long long int N,K;
	//int *z=new int[t];
	//int i=0;
	while(t--)
	{
		cin>>N>>K;
		getl(K);
		cout<<fun(N,K)<<endl;
	}
	/*for(int j=0;j<i;j++)
	{
		cout<<z[j]<<endl;
	}*/
	return 0;
}

