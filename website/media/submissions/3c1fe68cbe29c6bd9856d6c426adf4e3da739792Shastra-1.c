#include<stdio.h>

int main()
{
    int t,x,y,i,j;
    int c[4][4]={(3,2,1,0),(2,3,0,1),(1,0,3,2),(0,1,2,3)};
    scanf("%d",&t);
    while(t>0)
    {
             scanf("%d",&x);
             scanf("%d",&y);
             int remx=x%4;
             int quox=x/4;
             int remy=y%4;
             int quoy=y/4;
             int ans;
             if(quox=quoy)
                          ans=c[remx][remy];
             else
                          ans=c[remx][remy]+quox+quoy;
             printf("%d\n",ans);
             t--;       
    }    
}
