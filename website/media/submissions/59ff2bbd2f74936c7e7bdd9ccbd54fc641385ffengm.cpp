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
                 int t=1,temp=0;
                 int a=arr[0];
                 int b=arr[1];
                 //cout<<a<<" "<<b<<"\n";
                 temp=a+b-t;               
                for(i=2;i<n;i++)  
                {
                    b=arr[i];
                    //cout<<temp<<" "<<b<<"\n";
                    t++;
                    temp+=(b-t);    
                }
                //cout<<temp<<"\n";   
                if(temp%2==0)
                  cout<<"LOSE\n";
                else
                  cout<<"WIN\n";
      }
}
