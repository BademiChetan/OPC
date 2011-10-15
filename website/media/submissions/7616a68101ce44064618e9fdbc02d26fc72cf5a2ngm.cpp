#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
main()
{
      int t;
      cin>>t;
      while(t--)
      {
                int n,i;
                int arr[110],sum=0;
                cin>>n;
                for(i=0;i<n;i++)
                  {
                    cin>>arr[i];
                    sum+=arr[i];
                  }
                if((sum/n)%2==0)
                  cout<<"LOSE\n";
                else
                  cout<<"WIN\n";
      }
}
