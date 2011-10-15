#include<stdio.h>
#include<math.h>
#define L log(2)
float N;
int func(int m,int n)
{
        int k,max;
        double p;
        if(m==0&&n==0) return 0;
        if(m==0&&n==1) return 1;
        if(m==1&&n==0) return 1;
        if(m==1&&n==1) return 0;
        if(m>n) max=m;
        else max=n;
        N=pow(2,floor((log(max)/L))+1);
        N--;
        if((m>N/2&&n<N/2))
        {
                k=floor(log(m)/L);
                p=pow(2,k);
                return p+func(m-p,n);
        }
        if(m<N/2&&n>N/2)
        {
                return func(n,m);
        }
        if(m>N/2&&n>N/2)
        {
                return func(m-N/2,n-N/2);
        }
}
int main()
{
        int T,X,Y;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d%d",&X,&Y);
                printf("%d ",func(X,Y));
        }
        return 0;
}
