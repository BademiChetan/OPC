#include<stdio.h>
//#include<conio.h>
using namespace std;
typedef long long LL;
LL fast_modulo(LL a,LL b,LL c) 
{
	LL x=1,y=a;
	while(b) 
    {
		if(b&1)
			x=(x*y)%c;
		y=(y*y)%c;
		b>>=1;
	}
	return x%c;
}
int main()
{
   int T;
   scanf("%d",&T);
   while(T--)
   {
       LL N,K,a=2;
       scanf("%lld%lld",&N,&K);
       N=2*N;
       printf("%lld\n",fast_modulo(a,N,K));
   }
   //getch();
   return 0;
}
