#include<stdio.h>

typedef long long LL;

LL power(LL n,LL k,LL mod){
	LL result = 1,exp,base;
	exp=k;
	base=n;
	while(exp){
		if((exp & 1) == 1){
			result = (result*base)%mod;	
		}
		exp = exp >> 1;
		base = (base*base)%mod;
	}
	return result;
}

int main(){
	LL i,t;
	LL n,k,ans;
	scanf("%lld",&t);
	while(t--){
		ans = 2;
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++){
			ans = power(ans,2,k);
		}
		printf("%lld\n",ans);
	}
	return 0;
}