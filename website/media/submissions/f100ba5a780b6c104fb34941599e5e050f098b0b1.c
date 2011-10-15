#include<stdio.h>
#include<math.h>

void main()
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
        sum=2;
        for(i=1;i<=n[j];i++)
        {
            sum=sum*sum;


        }
        sum=sum%k[j];
    printf("%ld\n",sum);
}


}
