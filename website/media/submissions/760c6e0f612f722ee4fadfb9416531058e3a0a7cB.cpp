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
int grun[200][200];
int main(){
	long long int t,i,x,n,less,sum;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		sum=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&x);
			sum+=x;
		}
		less=(n*(n-1))/2;
		sum-=less;
		if(sum%2==1)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
}

