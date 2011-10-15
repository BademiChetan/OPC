#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define s(c) scanf("%d",&c);
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;


int main()
{
  int t;
  long long a,b;
  s(t);
  while(t--){
   scanf("%lld %lld",&a,&b);
   int hasil=2;
   for(long long i=1;i<=a;i++){
    hasil*=(hasil%b);        
           
   }
   printf("%lld\n",(hasil%b)); 
  }     
}
