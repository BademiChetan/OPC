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
     int count=0;
     int arr[1000];
     int j;
     arr[0]=-1;//arr[1]=-1;
     for(i=1;i<=N;i++)
     {
      powr=powr*powr;
      powr=powr%K;
      if(powr==arr[0])
      break;     
      arr[count]=powr;
      count++;
      //printf("%d   %d\n",count,powr);
      }
     
    printf("%d\n",arr[(N-1)%count]);
    
   }
}
