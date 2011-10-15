#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std; 

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

#define lim 31622 
#include<cstring>


int pr[10000],fil;

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
    
    int cases;
    int sx,phi;
    scanf("%d",&cases);
    long long e,m,m1;
    while(cases--)
    {
        scanf("%lld%lld",&e,&m);
        m1=m;
        phi=1;
        for(int i=0;pr[i]*pr[i]<m&&i<fil;i++){
            if(m==1) break;
            if(m%pr[i]==0){
                phi*=(pr[i]-1);
                m/=pr[i];
                while(m%pr[i]==0){
                    phi*=pr[i];
                    m/=pr[i];
                }
                //printf("left out is %d\n",m);
            }
        }
        if(m!=1) phi*=(m-1);
        //printf("phi is %d\n",phi);
        e=power_mod(2,e,phi);
        printf("%lld\n",power_mod(2,e,m1));
    }
    //system("pause");
    return 0;
}        
