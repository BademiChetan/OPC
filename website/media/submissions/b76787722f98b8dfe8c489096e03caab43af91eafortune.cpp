#include <iostream>
#include <cstdio>
using namespace std;


/* This function calculates (ab)%c */
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}



int mine(int n, int k)
{
  if ( n == 1)
    return 4 % k;
  else 
    return (mine(n-1,k)* mine(n-1,k)) % k;
}

int main()
{

  int t;
  cin>>t;

  while(t--){
    int x , y ;
    scanf("%d%d",&x,&y);
    cout << mine(x,y) <<endl;
  }
}
