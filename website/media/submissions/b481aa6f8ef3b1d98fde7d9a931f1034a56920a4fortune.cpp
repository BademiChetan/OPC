#include<stdio.h>
double square(double n)
{
       return n*n;
}

main()
{
    int t,i=1;
    double n,ans=2,k;
    scanf("%d",&t);
    while(t)
    {
            ans=2;
            i=1;
            scanf("%lf",&n);
            scanf("%lf",&k);
            
            while(i<=n)
            {
                   ans = square(ans);
                   i++; 
            }
            
            
           double woo = ans/k;
           int abc = woo;
           abc = ans - (abc*k);
            printf("%d\n",abc);
            t--;
        
    }

}

