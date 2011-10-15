#include<iostream>
#include<math.h>

using namespace std;

int l,n,m,k,t,i;
long long a[1009];
const int inf=1000000007;

int main()
{
    int j,k,x,y;
    cin>>t;
    for(i=0;i<t;i++)
    {
                    cin>>n>>m;
                    k=n/m;
                    a[i]=1;
                    if(m==2)
                    {
                            l=2*k-1;
                             for(j=1;j<=l;j++)
                             {a[i]=a[i]*2;
                             a[i]=a[i]%inf;
                             }
                    }
                    else
                    {
                        x=1;y=1;
                        for(j=1;j<=k;j++)
                        {
                                         x=x*2; x= x%inf;
                        }
                        for(j=1;j<=n;j++)
                        {
                                         y=y*2;y=y%inf;
                        }
                        a[i]=((m-1)*x + y)/m;
                        a[i]=a[i]%inf;
                    }
                    cout<<a[i]<<endl;
    }
    return 0;
}
