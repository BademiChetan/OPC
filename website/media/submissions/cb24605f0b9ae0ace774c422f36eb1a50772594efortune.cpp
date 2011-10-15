#include<iostream>
using namespace std;

#define LL long int


//2^1 = 10;
//2^2 = 100;
//2^8 = 100000000 = 9
LL power(LL x, LL MOD)
{
   LL result = 1;
   LL base=2;
   x++;
   while (x){
         if (x == 1)
            result = (result*base)%MOD;
         x--;
         base=(base*base)%MOD;
   }
   return result;
}

int main()
{
    int T;
    cin>>T;
    while (T--){
          LL N,K;
          cin>>N>>K;
          LL ans = power(N, K);
          cout<<ans<<endl;
    }    
}
