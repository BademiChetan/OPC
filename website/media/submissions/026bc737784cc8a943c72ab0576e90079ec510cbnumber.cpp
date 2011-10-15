#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdio>
using namespace std; 

int main()
{
  int t;
  cin>>t;

  while(t--){
  int x ;
  scanf("%d",&x);
  int sum =0;
  for(int i=0;i<x;i++)
    {
      int temp;
      scanf("%d",&temp);
      sum = sum+ temp;
    }
  int sub = 0;
  sub =( (x) * (x-1) )/2;
  int ans = sum - sub;
  if (ans %2 == 0)
    printf("LOSE\n");
  else
    printf("WIN\n");

  }
 
 
}
