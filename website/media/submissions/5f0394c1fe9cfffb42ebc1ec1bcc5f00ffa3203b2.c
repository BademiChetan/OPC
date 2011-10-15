#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int t,i,j,k,n,p;
    scanf("%d",&t);
    while(t--)
    {j=k=0;
     scanf("%d",&n);
     for(i=0;i<n;i++){scanf("%d",&p);if(p&1)j++;else k++;}         
              if(!((j==2&&k==n-2)||k==n))printf("LOSE\n");
              else printf("WIN\n");
              }
    
    
    return 0;
    }