#include<iostream>
using namespace std;
int main()
{
  int t,x,y,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int ans = -(n*(n-1))/2;
//     cout<<ans<<"\n";
    while(n--)
    {cin>>x; ans+=x;}
//     cout<<"ans = "<<x;
    if (ans%2) cout<<"WIN\n";
    else
      cout<< "LOSE\n";
    
  }
  return 0;
}