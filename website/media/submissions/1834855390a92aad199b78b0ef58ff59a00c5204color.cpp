#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdio>
using namespace std; 

int power[21];

int computepower()
{
  int value = 1;
  for(int i=0;i<21;i++)
    {
      power[i] = value;
      value = value * 2;      
    }
}

int compute(int x,int y){

 
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
  if (y == 0)
    return x;

  int x1 = log2(x);
  x1 = power[x1];
  int y1 = log2(y);
  y1 = power[y1];
  if(x1 == y1) {
    return compute(x - x1,y - y1);
  }  else if( x1 > y1) {
      return x1 + compute(x - x1, y);
      
    } else if (x1 < y1) {
      return y1 +  compute(x  , y - y1);
    }
      
  
}

int main()
{
  int t;
  cin>>t;
  computepower();
  while(t--){
  int x,y ;
  scanf("%d%d",&x,&y);
  cout <<compute(x,y)<<endl;
  }
 
 
}
