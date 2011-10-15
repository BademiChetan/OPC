#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
     long long int K,N;
    // scanf("%lld,%lld",&N,&K);
     cin>>N>>K;
     int powr=2;
     long long int i;
     for(i=1;i<=N;i++)
     {
      powr=powr*powr;
      powr=powr%K;
     }
   //  printf("%d\n",pow);
    printf("%d\n",powr);
   }
}
