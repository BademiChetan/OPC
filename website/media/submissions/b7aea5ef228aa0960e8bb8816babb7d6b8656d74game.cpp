#include"iostream"
#include"string.h"
using namespace std;
int dp[200][200];
int solve(int total,int odd)
{

	if(dp[total][odd]>0){
		return dp[total][odd];
	}
	if(total==1){
		if(odd==1){
			dp[1][1]=2;
			return 2;
		}
		else{
			dp[1][0]=1;
			return 1;
		}
	}
	int v1=0,v2=0;
	if((total-1)>=(odd-2) && odd-2>=0)
		v1=solve(total-1,odd-2);
	if((total-1)>=odd ){
		v2=solve(total-1,odd);
	}
	if(v1 && v2){
		if(v1==2 && v2==2)
			dp[total][odd]=1;
		else
			dp[total][odd]=2;
	}
	else{
		if(v1==1||v2==1){
			dp[total][odd]=1;
		}
		else{
			dp[total][odd]=2;
		}
	}
	return dp[total][odd];
}	
int main()
{
	memset(dp,0,sizeof dp);
	int test,n,i,a;
	cin>>test;
	while(test--){
		cin>>n;
		int odd=0;
		for(i=0;i<n;i++){
			cin>>a;
			if((a&1))
				odd++;
		}
		//cout<<odd << " " << n << endl;
		int res=solve(n,odd);
		//cout<<res<<endl;
		if(res==2){
			cout<<"LOSE\n";
		}
		else{
			cout<<"WIN\n";
		}
	}
	return 0;
}
