#include<iostream.h>
#include<conio.h>

double square(double n)
{
       return n*n;
}

int main()
{
    int t,i=1,k;
    double n,ans=2;
    cin>>t;
    while(t)
    {
            cin>>n;
            cin>>k;
            
            while(i<=n)
            {
                   ans = square(ans);
                   i++; 
            }
            int woo = ans/k;
            ans = ans -( woo*k);
            cout<<ans<<"\n";
            t--;
    }
}

