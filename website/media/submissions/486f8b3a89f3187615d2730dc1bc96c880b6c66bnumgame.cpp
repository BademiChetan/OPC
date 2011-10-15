#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);

// Variables

    int t;
    cin>>t;
    int n,i,p;
    int a[105];
    while(t--)
    {
         cin>>n;
         for(i=1;i<=n;i++)
         {
                   cin>>a[i];
         }
         
         for(i=1;i<=n;i++)
         {
                          p=a[i];
                          p+=a[i+1];
                          p-=i;
                          a[i+1]=p;
         }
         
         if(a[n]%2==0){
                       cout<<"LOSE"<<endl;
         }
         else
         {
             cout<<"WIN"<<endl;
         }
    }

    return 0;
}
