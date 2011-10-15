#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int T,i,sol;
long long N,K,p;
scanf("%d",&T);
while(T--)
{
scanf("%lld %lld",&N,&K);
p=1<<N;
sol=pow(2,p);
sol=sol%K;
printf("%d",sol);
}
getch();
return 0;
}
