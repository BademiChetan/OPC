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
   scanf("%I64d %I64d",&a,&b);
   int hasil=2;
   for(long long i=1;i<=(a%b);i++){
    hasil*=(hasil%b);        
           
   }
   printf("%I64d\n",(hasil%b)); 
  }     
}
