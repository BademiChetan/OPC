#include<iostream>
using namespace std;

main()
{
 int t;
 cin>>t;

 int n[t],k[t];
 long int fortune;
 int i,j;
 for(i=0;i<t;i++)
  cin>>n[i]>>k[i];

 for(i=0;i<t;i++)
 {
  fortune=2;

  for(j=0;j<n[i];j++)
   fortune*=(fortune);
   
  cout<<fortune%k[i]<<'\n';
 }
}
