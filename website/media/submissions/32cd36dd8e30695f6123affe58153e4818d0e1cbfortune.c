#include<stdio.h>
main()
{
      unsigned int t=0,arr[1000][2]={0},i,j,e;
      long double n=2;
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
                                      if(n>arr[i][1])
                                        break;
                                       }
              printf("%d",(int)n%arr[i][1]);
              if(i!=t-1)
               printf("\n");
             }
      getch();
}
