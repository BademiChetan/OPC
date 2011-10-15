#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
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
   printf("%lld\n",abs(b-a)); 
  }     
}
