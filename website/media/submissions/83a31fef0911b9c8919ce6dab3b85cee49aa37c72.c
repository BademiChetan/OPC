#include<stdio.h>

void solve(){


}

int main(){
	int t,n,a,i,sum1,sum2,ans;
	scanf("%d",&t);
	while(t--){
		sum1 = 0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a);
			sum1 += a;
		}
		sum2 = ((n-1)*n)/2;
		ans = sum1-sum2;
		if(ans%2 == 0)
			printf("LOSE\n");
		else
			printf("WIN\n");
		solve();
	}
	return 0;
}