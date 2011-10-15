#include<stdio.h>

int main()
{
    int t,a[100],sum=0,i,n;
    scanf("%d",&t);
    while(t--)
    {
              i=0;
              sum=0;
              scanf("%d",&n);
              while(n--)
              {
                        scanf("%d",&a[i]);
                        sum+=a[i];
                        i++;
                        }
                        if(sum%2==0)
                        printf("WIN\n");
                        else
                        printf("LOSE\n");
                        }
            
                        return 1;
                        }
                        
