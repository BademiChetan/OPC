#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
main()
{
      int b,a[3],i,h[3],c[3],j,w,k;  
      scanf("%d",&k);
      w=k;
      for(i=0;i<k;i++)
      {
      scanf("%d%d",&a[i],&h[i]);
      b=2;

      for(j=1;j<=a[i];j++)
      b=pow(b,2);
      c[i]=b%h[i];
      }
      for(i=0;i<w;i++)
      printf("%d\n",c[i]);
      getch();
      }
