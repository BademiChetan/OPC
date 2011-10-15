#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d",&t);
    //int cost[n],value[n],quant[n];
    long int n[t],k[t];
    int i,j,y;
    for(i=0;i<t;i++)
    {
        scanf("%ld%ld",&n[i],&k[i]);
    }
    y=2;
    for(i=0;i<t;i++){
    for(j=0;j<n[i];j++)
    {
        y*=(2%k[i]);
        y=y%k[i];
    }
    printf("%d\n",y);
    }
    return 0;
}
