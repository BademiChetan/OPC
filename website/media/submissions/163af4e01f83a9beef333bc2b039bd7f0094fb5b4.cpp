#include<cstdio>
#include<iostream>
#include<set>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;

#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define lim 31622 
#define MOD 1000000007

int pr[50000],fil;

int mult_inv(int a)
{
    int P=MOD,u1=1,v2=1,v1=0,u2=0,u3=0,v3=1;
    int q,b=P,r=P%a;
    while(r!=0)
    {
        q=P/a;
        u3=u1-q*u2;
        v3=v1-q*v2;
        u1=u2; v1=v2;
        u2=u3; v2=v3;
        P=a;
        a=r;
        r=P%a;
    }
    if(v3>=0) return v3;
    else return MOD+v3;
}

long long power_mod(long long a,long long e,long long m)
{
    long long i=a,d=1;
    while(e!=0)
    {
        if(e%2==1)
        {
            d*=i;
            d%=m;
        }    
        i*=i;
        i%=m;
        e=e>>1;
    }
    return d;
}

int main()
{
    bool is_prime[lim+1];
    memset(is_prime,true,lim);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<lim;i++){
        if(!is_prime[i]) continue;
        else{
            for(int j=i*i;j<lim;j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(int i=2;i<lim;i++) if(is_prime[i]) pr[fil++]=i;
    
    int cases,e;
    ll n,p,result;
    scanf("%d",&cases);
    while(cases--){
        scanf("%lld%lld",&p,&n);
        result=0;
        vpi fctr;
        ll n1=n;
        for(int i=0;pr[i]*pr[i]<n1;i++){
            if(n1==1) break;
            if(n1%pr[i]==0){
               e=1;
               n1/=pr[i];
               while(n1%pr[i]==0) n1/=pr[i],e++;
               fctr.pb(mp(pr[i],e));
           }
       }
       if(n1!=1) fctr.pb(mp(n1,1));
       int arr[1<<15]={},phi[1<<15],dv,fl,prp;
       arr[0]=1;
       dv=1;
       fl=1;
       for(int i=0;i<(1<<15);i++) phi[i]=1;
       for(int i=0;i<fctr.size();i++){
           prp=1;
           for(int iter=1;iter<=fctr[i].S;iter++){
               prp*=fctr[i].F;
               for(int j=0;j<dv;j++){
                   arr[fl]=arr[j]*prp;
                   if(iter==1) phi[fl]*=(fctr[i].F-1);
                   else phi[fl]*=fctr[i].F;
                   fl++;
               }    
           }
           dv=fl;
       }
       for(int i=0;i<dv;i++){
           if(arr[i]%2==1) (result+=(power_mod(2,p/arr[i],MOD)*phi[i]))%=MOD;
       }
       (result*=mult_inv(n))%=MOD;
       printf("%lld\n",result);
   }
   return 0;
}

   
