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
	int T,N,K;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		if(K==1){
			printf("0\n");
			continue;
		}
		
		map<int ,int> mp;
		map<int, int> rev;
		
		mp[2]=0;
		rev[0]=2;
		long long val=2;
		int xx,i;
		for(i=1;i<=N;i++){
			val=(val*val)%K;
			if(mp.find(val)==mp.end()){
				mp[(int)val]=i;
				rev[i]=(int)val;
			}
			else{
				//xx=st.find(val)-st.begin();
				break;
			}
		}
		if(i==N+1){
			printf("%d\n",(int)val);
			continue;
		}
		xx=mp[val];
		int len=mp.size()-xx;
		//cout<<len<<endl;
		//cout<<i<<" "<<xx<<endl;
		N-=xx;
		N%=len;
		if(N==0) N=len;
		printf("%d\n",rev[xx+N-1]);
	}
		
	return 0;
}
