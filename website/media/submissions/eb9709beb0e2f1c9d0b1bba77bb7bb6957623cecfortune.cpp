#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long int64;
int n,k,pk;

int64 powmod(int64 a,int p,int md){
   int64 r = 1;
   while(p){
     if(p%2==1) r = r*a; a = a*a;
     r %= md; a %= md; p /= 2;
   }
   return r;
}

void calculate(){
   int t = k; pk = k;
   for(int i=2;i*i<=t;++i) 
     if(t%i==0){
       pk /= i; pk *= i-1;
       while(t%i==0) { t/=i; }
     }
   if(t>1){
      pk *= (t-1); 
   }
   return ;
}

int main(){
  int tcase; scanf("%d",&tcase);
  while(tcase--){
    scanf("%d%d",&n,&k);
    calculate();
    printf("%lld\n",powmod(2,powmod(2,n,pk),k));
  }
  return 0;
}
