#include<stdio.h>
#include<math.h>

int main()
{

    long int sum=2;
    int t,j,n[1001],k[1001],i;


    scanf("%d",&t);

    for(j=1;j<=t;j++)
    {
    scanf("%d %d",&n[j],&k[j]);
    }



    for(j=1;j<=t;j++)
    {
        sum=2;
    for(i=1;i<=n[j];i++)
    {

        sum=sum*sum;

    }

    sum=sum%k[j];
    printf("%ld\n",sum);
}

    return 0;
}
