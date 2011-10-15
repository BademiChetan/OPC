#include"stdio.h"
void inverse(int x,int p,int &a,int &b)
{
	if(x==1){a=1,b=0;return;}
	inverse(p%x,x,b,a);
	long long ap=a-(long long)(p/x)*b;
	if(ap>p||ap<0){ap=(p+(ap%p))%p;b=(1-ap*x)/p;}
	a=(int) ap;
}
int inverse (int x,int p)
{
	int l,m;
	inverse(x,p,l,m);
	return l;
}
long long power(int a,int b)
{
	long long ans=1,pow=a;
	while(b)
	{
		if(b&1)ans=(ans*pow)%1000000007;
		pow=(pow*pow)%1000000007;
		b>>=1;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long long ans;
		if(k!=2)
		ans=(inverse(k,1000000007)*(power(2,n)+(power(2,n/k)*(k-1))%1000000007))%1000000007;
		else ans=power(2,n-1);
		printf("%Ld\n",ans);
	}
}
