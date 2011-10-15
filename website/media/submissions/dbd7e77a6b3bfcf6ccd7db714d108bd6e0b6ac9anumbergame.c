#include<stdio.h>
int main()
{
    int T,N;
    int x,y;
    scanf("%d",&T);
    while(T--)
{
    int t=0;
    int sum=0;
    scanf("%d",&N);
    int n=(N*(N-1))/2;
    while(N--)
       {  scanf("%d",&x);
              sum+=x;
       }
       sum-=n;
    if(sum%2==0)
     printf("LOSE\n");
     else
     printf("WIN\n");
     }
    
    //system("pause");
    return 0;
}
