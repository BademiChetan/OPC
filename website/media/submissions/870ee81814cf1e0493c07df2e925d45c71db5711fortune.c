#include<stdio.h>
main()
{
      int t=0,arr[1000][2]={0},i,j;
      int n=2;
      scanf("%d",&t);
      for(i=0;i<t;i++)
      {
                      scanf("%d %d",&arr[i][0],&arr[i][1]);
                      }
      for(i=0;i<t;i++)
      {
              
              n=pow(2,(pow(2,n)));
              printf("%d\n",n%arr[i][1]);
              
             }
      return 0;
}
