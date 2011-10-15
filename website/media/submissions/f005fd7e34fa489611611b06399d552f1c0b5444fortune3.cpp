#include<stdio.h>
int main()
{
    long int t,n,k;
    scanf("%ld",&t);
    while(t--)
    {
              scanf("%ld  %ld",&n,&k);
              if(n==1)
              printf("%d\n",(4%k));
              else if(n%2==0)
              printf("%d\n",(16%k));
              else
              printf("%d\n",(256%k));
              }
              return 0;
              }
