#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
bool isprime[34000];
vector<int> prm;
void precomp(){
	int i,j,fl;
	fill(isprime,isprime+32000,true);
	for(i=2;i<=32000;i++){
		fl=0;
		if(isprime[i]){
			prm.PB(i);
			for(j=i+i;j<=32000;j+=i)
				isprime[i]=0;
		}
	}
	prm.PB(2000000000);
}
LL seive(int k){
	vector<int> v;
	LL pro=1,pro2=1,n=k;
	bool fl=0;int i;
	for(i=0;prm[i]<k;i++){
		fl=0;
		while(k%prm[i]==0){
			k/=prm[i];
			fl=1;	
		}
		if(fl)
			v.PB(prm[i]);
	}
	if(k!=1)
		v.PB(k);
	for(i=0;i<v.size();i++){
		pro*=(v[i]-1);
		pro2*=v[i];
	}
	return ((pro*n)/pro2);
}
LL modexp(LL a,LL b,LL c){
	LL cur=a,ans=1;
	while(b){
		if((b&1)){
			ans*=cur;
			if(ans>=c)
				ans%=c;
		}
		cur*=cur;
		if(cur>=c)cur%=c;
		b>>=1;
	}
	return ans;
}
int main(){
	int t,n,k;
	precomp();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		printf("%Ld\n",modexp(2,modexp(2,n,seive(k)),k));
	}
	return 0;
}

