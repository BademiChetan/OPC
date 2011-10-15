#include<stdio.h>
int main()
{
    int t,i,x,y,max;
    int ans;
    int n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
                  scanf("%d%d",&x,&y);
                  if(x>y)
                  max=x;
                  else
                  max=y;
                  max=max+1;
                  ans=x+y;
                  if(ans>max)
                  ans=ans-max-1;
                  printf("%d\n",ans);
                  }
                  //getch();
                  return 0;
                  }
                  
                    
