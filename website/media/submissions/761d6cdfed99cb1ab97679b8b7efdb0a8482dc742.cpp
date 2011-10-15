#include <iostream>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T>0){T--;
    int n,p=0,x;
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;p=(p+x)%2;}
    if(p==0&&n%4<2){cout<<"LOSE\n";}
    else if(p==1&&n%4>1){cout<<"LOSE\n";}
    else{cout<<"WIN\n";}
  }
}
