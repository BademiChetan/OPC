#include <stdio.h>

int main(void)
{
    int t, i,n,k,s,val=2;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n,&k);
        val =2;
        for(s=1;s<=n;s++)
            val = val*val;
        printf("%d",val%k);
    }
    return 0;
}
