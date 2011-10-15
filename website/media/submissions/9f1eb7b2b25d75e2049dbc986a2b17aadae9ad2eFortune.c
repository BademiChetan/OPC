#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, i,n,k,s,val=2;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n,&k);
        val = pow(2,pow(2,n));

        printf("%d",val%k);
    }
    return 0;
}
