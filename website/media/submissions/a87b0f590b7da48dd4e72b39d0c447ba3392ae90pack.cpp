#include <iostream>
#include <cstdio>
using namespace std;
const long long int INF=(1ll<<62);
long long int dp[2][100000001];
long long int cost[10];
long long int f[10];
long long int value[10];
int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n,W;
		scanf("%d%d",&n,&W);
		int ncost[50],nval[50];
		int top=1;
		for ( int i=0;i<n;++i){
			scanf("%lld%lld%lld",&cost[i],&value[i],&f[i]);
			int fc=1;
			int tmp=f[i];
			while(tmp){
				if(tmp%2){
									ncost[top]= cost[i]*fc;
									nval[top++]= value[i]*fc;
				}
				fc<<=1;
				tmp>>=1;
			}
		
		}
			//cout<<"top is "<<top<<endl;
			for ( int i=1;i<top;++i){
					
				for ( int j=1;j<=W;++j){
					dp[i%2][j]=INF;
					if ( ncost[i]>j)dp[i%2][j]=0;
					else {
						dp[i%2][j]= max ( dp[(i+1)%2][j],dp[(i+1)%2][j-ncost[i]] + nval[i]);
						}
						//printf("%d ",dp[i%2][j]);
				}
				
			}
			
			printf("%lld\n",dp[(top+1)%2][W]);
		
		
		
		
	}
return 0;
}
