#include<stdio.h>
#include<math.h>

int main()
{

    long int sum=2;
    int t,j,n[1001],i;
    long int k[1001];

    scanf("%d",&t);

    for(j=1;j<=t;j++)
    {
    scanf("%d %ld",&n[j],&k[j]);
    }



    for(j=1;j<=t;j++)
    {


        sum=pow(sum,n[j]);

    sum=sum%k[j];
    printf("%ld\n",sum);
}

    return 0;
}
