// In the name of Allah
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int t,x,y,q,w,s=0;
  cin>>t;
  while(t--){
    cin>>x>>y;
    s=0;
    if(x>y)
      swap(x,y);
    while(y>0){
      q=log2(x);
      w=log2(y);
      if(q==w){
	x-=pow(2,q);
	y-=pow(2,q);
      }
      if(q!=w){
	y-=pow(2,w);
	s+=pow(2,w);
      }
      if(x>y)
	swap(x,y);
    }
    //s+=y;
    cout<<s<<endl;
  }
  return 0;
}
