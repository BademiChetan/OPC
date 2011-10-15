# include<iostream>
# include<stdio.h>
# include<string.h>
# include<math.h>
int main()
{
	unsigned long long t,n,k,res=2,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		res=(unsigned long long)(pow(2,pow(n,2)));
		res=res%k;
		printf("%lld\n",res);
		res=2;
	}
	return(0);
}
		
