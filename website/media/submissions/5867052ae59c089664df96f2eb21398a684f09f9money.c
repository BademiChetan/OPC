#include<stdio.h>
#include<stdint.h>

int main()
{
    int64_t n,i,j;

    scanf("%I64d",&n);
    int64_t a[n],k[n];

    int64_t max=0;
    for(i=0;i<n;i++)
    {

        scanf("%I64d",&a[i]);
        scanf("%I64d",&k[i]);
        if(max<a[i])
        max=a[i];

    }
    int64_t b[max+1];b[0]=2;
    for(j=1;j<=max;j++)
        {
           b[j]=b[j-1]*b[j-1];
        }
    for(i=0;i<n;i++)
    printf("%I64d\n",b[a[i]]%k[i]);
    return 0;
}
