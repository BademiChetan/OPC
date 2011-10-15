#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	long long T,N,K;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&N,&K);
		if(K==1){
			printf("0\n");
			continue;
		}
		
		map<long long,long long> mp;
		map<long long, long long> rev;
		
		mp[2]=0;
		rev[0]=2;
		long long val=2;
		long long xx,i;
		for(i=1;i<=N;i++){
			val=(val*val)%K;
			if(mp.find(val)==mp.end()){
				mp[val]=i;
				rev[i]=val;
			}
			else{
				//xx=st.find(val)-st.begin();
				break;
			}
		}
		if(i==N+1){
			printf("%lld\n",val);
			continue;
		}
		xx=mp[val];
		long long len=mp.size()-xx;
		//cout<<len<<endl;
		//cout<<i<<" "<<xx<<endl;
		N-=xx;
		N%=len;
		if(N==0) N=len;
		printf("%lld\n",rev[xx+N-1]);
	}
		
	return 0;
}
