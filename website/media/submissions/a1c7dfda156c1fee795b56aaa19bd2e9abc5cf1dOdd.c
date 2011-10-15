#include<stdio.h>
int i,j,k;
long long K;
long long modd(int k){
    long long ans=1;
    long long pow=2;
    while(k){
        if(k & 1) ans=(ans*pow)%K;
        pow=(pow*pow)%K;
        k=k/2;
    }
    return ans;
}
int main(){
    int t;
    long long n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&K);
        printf("%lld\n",modd(modd(n)));
    }
    return 0;
}
