#include<iostream>
#include<cstdio>
using namespace std;

typedef long long lint;

/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b){
        if(b&1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b>>=1;
    }
    return x%c;
}

/* This function calculates (ab)%c */
lint modulo(lint a,lint b,lint c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b){
        if(b&1){
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b>>=1;
    }
    return x%c;
}

 lint fi(lint n)
     {
       lint result = n;
       for(lint i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }

int main()
{
    int n,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        lint res=fi(k);
        lint power=modulo(2,n,res);
        lint ans=modulo(2,power,k);
        cout<<ans<<"\n";
    }
    return 0;
}
