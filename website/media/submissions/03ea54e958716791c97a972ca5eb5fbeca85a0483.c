#include<stdio.h>

typedef long long LL;
int factors[1000];

int factorize(LL n){
	int cnt=0,i,tmp;
	tmp=n;
	for(i=2;i*i<=n;i++){
		if(n%i == 0){
			factors[cnt++] = i;
			while(n%i == 0){
				n = n/i;
			}
		}
	}

	if(n>1){
		factors[cnt++] = n;
	}

	return cnt;
}

LL phi( LL n ){
    int fc,i;
    fc = factorize(n);
    for(i = 0; i < fc; i++ ){
        n /= factors[i];
        n *= factors[i] - 1;
    }
    return n;
}

LL power(LL n,LL k,LL mod){
	LL i,result = 1,exp,base;
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

LL brute(LL n,LL k){
	LL ans=2,i;
	for (i=0;i<n;i++)
		ans = (ans*ans)%k;
	return ans;
}

int main(){
	LL i,t,P,X,m;
	LL n,k,ans;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		P = phi(k);
		X = power(2,n,P);
		ans = power(2,X,k);
		printf("%lld\n",ans);
	}
	return 0;
}