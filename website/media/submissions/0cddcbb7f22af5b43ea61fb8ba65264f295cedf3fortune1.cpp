#include<cstdio>
#include<cmath>
using namespace std;
int totient(int K)
{
	int phi,i,t,s;
	i=2;
	t=K;
	s=sqrt(K);
	phi=K;
	while(i<=s && t>1)
	{
		if(t%i==0)
		{
			while(t%i==0) t/=i;
			phi=(phi*(i-1))/i;
		}
		i++;
	}
	if(t>1) phi=(phi*(t-1))/t;
	return phi;
}
int mod(int a,int b)
{
	int p=2,ans=1;
	while(a)
	{
		if(a%2)
		{
			ans=(ans*p)%b;
		}
		a/=2;
		p=(p*p)%b;
	}
	return ans;
}
int main()
{
	int T,N,K,phi,m,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		phi=totient(K);
		m=mod(N,phi);
		ans=mod(m,K);
		printf("%d\n",ans);
	}
}
		
