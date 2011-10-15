#include <stdio.h>
int main()
{
        int t, n, k,i,j;long s;
        scanf("%d", &t);
        for(i=0;i<t;i++)
        {
                scanf("%d %d", &n, &k);
                s=2;
                for(j=0;j<n;j++)
                {
                        s=(s*s)%k;
                }
                printf("%ld\n", s);
        }
        return 0;
}

