#include<iostream>
#include<cstdio>
#define ll unsigned long long int 
using namespace std;

ll fun(ll n,ll k){
	ll p=2;
	ll i=0;
	while(i<n && p <= k){
		p=p*p;
		i++;
	}
	return p%k;
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
