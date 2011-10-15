#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
      long long int K,N;
      int flag=0;
      scanf("%lld%lld",&N,&K);
      int powr=2;
      long long int i;
      int count=0;
      int arr[1000];
      int j;
      arr[0]=-1;
      for(i=1;i<=N;i++)
      {
       powr=powr*powr;
       powr=powr%K;
       if(powr==arr[0])
       {
        flag=1;
        break;
       }     
       arr[count]=powr;
       count++;
      }
      if(flag==1)
             printf("%d\n",arr[(N-1)%count]);
      else
             printf("%d\n",powr);
    }
   return 0;
}
