#include<stdio.h>
double square(double n)
{
       return n*n;
}

main()
{
    int t,i=1,k;
    double n,ans=2;
    scanf("%d",&t);
    while(t)
    {
            scanf("%l",&n);
            scanf("%d",&k);
            
            while(i<=n)
            {
                   ans = square(ans);
                   i++; 
            }
            int woo = ans/k;
            ans = ans -( woo*k);
            printf("%l",ans);
            t--;
    }

}

