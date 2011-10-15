#include<iostream>
#include<cstdio>
#define ll long long int 
using namespace std;

ll fun(ll n,ll k){
	if(n==1){
		return 4%k;
	}
	ll p = fun(n/2,k);
	return ((p%k)*(p%k))%k;
}
int main(){
	int t,i,j,k,l,m,n;
	ll N,K;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&N,&K);
		printf("%lld\n",fun(N,K));
	}
	return 0;
}
