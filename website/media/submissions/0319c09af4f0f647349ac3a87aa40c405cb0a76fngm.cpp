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
                int n,i,j=0;
                int arr[110],sum=0;
                cin>>n;
                for(i=0;i<n;i++)
                  {
                    cin>>arr[i];
                  }
                int t=1;
                for(i=0;;i++)
                {
                  int a=arr[0];
                  int b=arr[1];
                  cout<<a<<" "<<b<<"\n";
                  arr[0]=a+b-t;
                  for(j=2;j<n;j++)
                    arr[j-1]=arr[j];
                  t++;
                  if(i==n-2)
                    break;
                }
                cout<<arr[0]<<"\n";   
                if(arr[0]%2==0)
                  cout<<"LOSE\n";
                else
                  cout<<"WIN\n";
      }
}
