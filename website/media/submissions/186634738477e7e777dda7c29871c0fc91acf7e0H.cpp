#include<iostream>
#include<math.h>

using namespace std;

int l,n,m,k,t,i;
long long a[1009];

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {cin>>n>>m;
    k=n/m;
    if(m==2)
    {
            l=2*k-1;
    a[i]=pow(2,l);
    a[i]=a[i]%1000000007;
    }
    else
    {a[i]=((m-1)*pow(2,k)+pow(2,n))/m;
    a[i]=a[i]%1000000007;
    }
    }
    for(i=0;i<t;i++)
    cout<<a[i]<<endl;
    return 0;
}
