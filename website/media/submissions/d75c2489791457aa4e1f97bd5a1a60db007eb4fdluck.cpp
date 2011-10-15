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
      scanf("%lld%lld",&N,&K);
      long long int powr=2;
      long long int i;
      long long int count=0;
      long long int arr[100000];
      arr[0]=-1;
      
      for(i=0;i<N;i++)
      {
       powr=(powr*powr);
       powr=(powr%K);
       if(powr==arr[0])
         break;
       arr[count]=powr;
       count++;
      }
     
      printf("%lld\n",arr[(N-1)%count]);
    }
   return 0;
}