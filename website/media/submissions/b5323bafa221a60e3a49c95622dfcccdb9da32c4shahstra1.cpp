#include<iostream>
using namespace std;
int main()
{
    int t,n,tmp,a,s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>n;
            a=0;
           s=0;
           // int a[n];
            for(int j=0;j<n;j++)
            {
                  cin>>tmp;
                  a=a+tmp;
                  //s=s+j;
            }
            a=a-(n*(n-1))/2;
            if(a%2==0)
            cout<<"LOSE"<<endl;
            else
            cout<<"WIN"<<endl;
                    
    }
    //cin>>n;
    return 0;
}
