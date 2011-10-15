#include<iostream>
using namespace std;

int main()
{
  int t,i,n,k,a[1000],l,j;
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n>>k;
    l=2;
    for(j=1;j<=n;j++)
      l=l*l;
    a[i]=l%k;
  }
  for(i=0;i<t;i++)
    cout<<a[i]<<endl;
  return 0;
}
