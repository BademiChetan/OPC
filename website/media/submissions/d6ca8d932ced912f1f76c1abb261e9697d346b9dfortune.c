#include<stdio.h>
main()
{
      int n=2,d=0,t=0,arr[1000][2],i,j;
      scanf("%d",&t);
      for(i=0;i<t;i++)
      {
                      scanf("%d %d",&arr[i][0],&arr[i][1]);
                      }
      for(i=0;i<t;i++)
      {
              n=2;
              for(j=0;j<arr[i][0];j++)
              {
                              n*=n;
                              }
              printf("%d",n%arr[i][1]);
              if(i!=t-1)
               printf("\n");
              }
      return 0;
}
