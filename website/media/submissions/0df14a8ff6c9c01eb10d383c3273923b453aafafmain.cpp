#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long mulmod(long long int a,long long int b,long long int c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

int modulo(long long int a,long long int b,long int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x = mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b/=2;
    }
    return x%c;
}


int main()
{
    int t;
    long long int n,k;
    cin>>t;
    while(t--)
    {
     scanf("%lld%lld",&n,&k);
     printf("%d",modulo(2,pow(2,n),k));
    }
    return 0;
}
