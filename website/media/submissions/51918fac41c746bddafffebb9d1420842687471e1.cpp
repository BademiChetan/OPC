#include<iostream>
using namespace std;
int main()
{
  int t,x,y;
  cin>>t;
  while(t--)
  {
    cin>>x>>y;
    int d = x+y;
    int ans;
    if( d%4==3)
      cout<<d<<endl;
    else if(d%4==1)
    {
      ans = d - 4*((x>y)?y:x/2);
      cout<<ans<<endl;
    }
    else
    {
      if(((y-x)*(y-x))%16==0)
	cout <<((y-x)>0?(y-x):(x-y))<<"\n";
      else{
	int q =(y-x)>0?(y-x):(x-y); 
	int w =(y-x)>0?(y):(x);
// 	if(x>y)
// 	  cout<<x+((y1)/2)*4<<endl;
// 	else
// 	  cout<<y+((x1)/2)*4<<endl;
	int y = (q/4+2)*2;
	cout << q+((w-q)%y/2)*4<<endl;
      }
    }
  }
  return 0;
}