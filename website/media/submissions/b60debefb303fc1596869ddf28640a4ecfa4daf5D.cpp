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
LL seive(int k){
	vector<int> v;
	LL pro=1,pro2=1,n=k;
	bool fl=0;int i;
	for(i=2;i<min(k,32000);i++){
		fl=0;
		while(k%i==0){
			k/=i;
			fl=1;	
		}
		if(fl)
			v.PB(i);
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
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		printf("%Ld\n",modexp(2,modexp(2,n,seive(k)),k));
	}
	return 0;
}

