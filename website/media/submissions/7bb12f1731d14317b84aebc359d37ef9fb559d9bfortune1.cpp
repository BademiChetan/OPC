#include<iostream>
#include<math.h>
using namespace std;

main()
{
 int t;
 cin>>t;

 float n[t],k[t];
 double fortune;
 int i,j;
 for(i=0;i<t;i++)
  cin>>n[i]>>k[i];

 for(i=0;i<t;i++)
 {
  fortune=pow(2,pow(2,n[i]));
  cout<<int(fortune)%int(k)<<'\n';
 }
}
