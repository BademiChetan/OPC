#include<stdio.h>
using namespace std;
int fast_modulo(int a,int b,int c) 
{
	int x=1,y=a;
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
       int N,K;
       scanf("%d%d",&N,&K);
       printf("%d\n",fast_modulo(2,2*N,K));
   }
   return 0;
}
