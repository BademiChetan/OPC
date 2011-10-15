#include<stdio.h>
int main()
{   int t,n,a,b,i;
    scanf("%d",&t);
    while(t--)
    {         a=0;
              scanf("%d",&n);
              for(i=0;i<n;i++)
              {         scanf("%d",&b);
                        a+=b;
              }
              n=(n-1)%2+((n-1)/2);
              if(n%2==a%2)printf("LOSE\n");
              else printf("WIN\n");
    }
    return 0;
}
