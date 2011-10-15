#include<stdio.h>
int main()
{
    int n,k,i,t,j,c,temp;
    scanf("%d",&t);
    int a[t];
    for(i=1;i<=t;i++)
    {
    scanf("%d %d",&n,&k);
    a[i]=temp=0;
    for(j=1;j<=n;j++)
    { 
    temp=temp+j;
    for(c=j+1;c<=n;c++)
    {
    if((j+c)%k==0)
    a[i]++;
    }
    if(j%k==0)
    a[i]++;
    
    }
        if(temp%k==0)
        a[i]=a[i]+1;

    }
        for(i=1;i<=t;i++)
        printf("%d\n",a[i]+1);
       
    return 0;
    
    } 
