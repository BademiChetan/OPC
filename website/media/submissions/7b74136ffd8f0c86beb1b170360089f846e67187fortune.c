#include <stdio.h>
int main()
{
        int t, n, k,i,j,l,s;long p;
        scanf("%d", &t);
        for(i=0;i<t;i++)
        {
                scanf("%d %d", &n, &k);
                s=2;
                for(j=0;j<n;j++)
                {	
			l=k/s+1;if(l<=s) {p=(l*s)%k;
			s=(p*(s/l+s%l))%k;}
			else s=(s*s)%k;
			
                }
                printf("%d\n", s);
        }
        return 0;
}

