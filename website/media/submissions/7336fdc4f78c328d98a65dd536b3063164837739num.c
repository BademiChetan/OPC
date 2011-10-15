#include<stdio.h>

int main()
{
    int t,k,s,r,g=0,y,j;
    scanf("%d",&t);
    while(t--)
    {
        g=0;
      scanf("%d",&k);
       r=((k-1)*k)/2;
        for(j=0;j<k;j++)
        {scanf("%d",&s);g=g+s;}
        y=g-r;
        if(y%2==0)
        printf("LOSE\n");
        else
        printf("WIN\n");
    }
    return 0;
}


