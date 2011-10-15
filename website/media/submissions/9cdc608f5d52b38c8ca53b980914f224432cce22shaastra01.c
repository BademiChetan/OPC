#include<stdio.h>

int main()
{
   int test,x,y,res,temp;
   scanf("%d",&test);
   while(test--)
   {
      scanf("%d%d",&x,&y);
      if(x==y)
      {
         res=0;
         printf("%d\n",res);
         continue;
      }
      if(y>x)
      {
         temp=y;
         y=x;
         x=temp;
      }
      if(x%2==0)
      {
         res=x+y;
         printf("%d\n",res);
         continue;
      }
      else
      {
         res=x-y;
         printf("%d\n",res);
         continue;
      }

   }
   return 0;
}
