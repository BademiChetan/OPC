// In the name of Allah
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int t,x,y;
  cin>>t;
  while(t--){
    cin>>x>>y;
    if(x<y)
      swap(x,y);
    cout<<x-y<<endl;
  }
  return 0;
}
