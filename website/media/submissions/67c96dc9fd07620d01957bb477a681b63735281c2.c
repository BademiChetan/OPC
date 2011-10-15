#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int t,i,j,k,n,p;
    scanf("%d",&t);
    while(t--)
    {j=0;k=0;
     scanf("%d",&n);
     for(i=0;i<n;i++){scanf("%d",&p);if(p&1)j++;else k++;}         
             if(n==1){if(j)printf("WIN\n");else if(k)printf("LOSE\n");}
              else {
                   if(j%2==0)printf("WIN\n");
                   else printf("LOSE\n");
                   }
              }
    
    
    return 0;
    }
