#include<iostream>
using namespace std;

main()
{
 int t;
 cin>>t;
 
 long int r;
 int n[t],k[t];

 for(int i=0;i<t;i++)
  cin>>n[i]>>k[i];
 
 for(int i=0;i<t;i++)
 {
  r=2;
  for(int j=0;j<n[i];j++)
   r*=r%k[i];
  cout<<r<<'\n';
 }
}
