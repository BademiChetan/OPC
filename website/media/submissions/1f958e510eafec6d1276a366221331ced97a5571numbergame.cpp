#include<iostream>
using namespace std;

main()
{
 int t;
 cin>>t;
 
 int n,win[t];
 for(int i=0;i<t;i++)
 {
  cin>>n;
  int A[n],sum=0;
  for(int j=0;j<n;j++)
  {
   cin>>A[j];
   sum=sum+A[j];
  }
  sum=sum-(n-1)*n/2;
  if((sum%2)==0)
   win[t]=0;
 }

 for(int i=0;i<t;i++)
  if(win[t]==0)
   cout<<"LOSE\n";
  else
   cout<<"WIN\n";
}
 
