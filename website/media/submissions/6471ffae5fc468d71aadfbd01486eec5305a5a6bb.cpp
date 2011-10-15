// In the name of Allah
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int t,s,n,x;
  cin>>t;
  while(t--){
    cin>>n;
    s=-(n*(n+1)/2);
    while(n--){
      cin>>x;
      s+=x;
    }
    if(s%2)
      cout<<"WIN"<<endl;
    else
      cout<<"LOSE"<<endl;
  }
  return 0;
}
