#include<stdio.h>

int color(int x,int y, int yet)
{
    int u=((x>y)?x:y)+1,l=((x>y)?y:x)+1,i;
    if(l==1) return u+yet-1;
    for(i=2;i<u;i*=2);i/=2;
    if(l>i) { return color(u-i-1,l-i-1,yet);}
    else { return color(u-i-1,l-1,yet+i);}
}

int main()
{
    int t; scanf("%d",&t);
    for(;t>0;t--)
    {
        int x,y;
        scanf("%d",&x);scanf("%d",&y);
        printf("%d\n",color(x,y,0));
    }
    return 0;
}
