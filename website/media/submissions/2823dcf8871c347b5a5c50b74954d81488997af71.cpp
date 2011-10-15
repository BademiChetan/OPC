#include<iostream>
using namespace std;
int main()
{
  int t,x,y;
  cin>>t;
  while(t--)
  {
    cin>>x>>y;
    if(y<=x)
      cout<<x+y<<"\n";
    else if(y<=2*x)
      cout<<y-x<<"\n";
    else
      cout<<y<<"\n";
  }
  return 0;
}