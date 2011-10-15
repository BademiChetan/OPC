#include <iostream>
#include <vector>
#include <cmath> 

using namespace std; 



int compute(int x,int y){

  // cout << x  << " " << y<<endl;
  if(x == 0 && y == 0)
    return 0;
  if(x == 1 && y == 0)
    return 1;
  if(x == 0 && y == 1)
    return 1;
  if(x == 1 && y == 1)
    return 0;
  if(x == 0 )
    return y;
  if (y==0)
    return x;

  int x1 = log2(x);
  x1 = pow(2,x1);
  int y1 = log2(y);
  y1 = pow(2,y1);
  if(x1 == y1) {
    return compute(x - x1,y - y1);
  }  else if( x1 > y1) {
      return x1 + compute(x - x1, y);
      
    } else if (x1 < y1) {
      return  compute(x  + y1, y);
    }
      
  
}

int main()
{
  int t;
  cin>>t;
  while(t--){
  int x,y ;
  cin>>x>>y;
  cout <<compute(x,y)<<endl;
  }
  
}
