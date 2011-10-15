#include<iostream>
#include<math.h>

using namespace std;

int l,n,m,k,t,i,a[1009];

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
    }
    else
    a[i]=((m-1)*pow(2,k)+pow(2,n))/m;
}
    for(i=0;i<t;i++)
    cout<<a[i]<<endl;
    system("pause");
    return 0;
}
