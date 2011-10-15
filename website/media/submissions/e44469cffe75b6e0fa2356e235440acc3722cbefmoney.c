#include<stdio.h>
#include<stdint.h>

int main()
{
    int64_t n,a,b,i,j,k;

    scanf("%I64d",&n);
    int64_t ans[n];
    for(i=0;i<n;i++)
    {
        b=2;
        scanf("%I64d",&a);
        for(j=0;j<a;j++)
        {
           b*=b;
        }
        scanf("%I64d",&k);
        b%=k;
        ans[i]=b;
    }
    for(i=0;i<n;i++)
    printf("%I64d\n",ans[i]);
    return 0;
}
