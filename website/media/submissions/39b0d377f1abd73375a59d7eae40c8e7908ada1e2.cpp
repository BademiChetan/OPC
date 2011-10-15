#include<cstdio>
main() {
	int t,n,sum,x;
	scanf("%d",&t);
	while(t--) {
		sum = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%d",&x);
			sum += x;
		}
		sum -= n*(n-1)/2;
		if(sum%2==0)
		printf("LOSE\n");
		else
		printf("WIN\n");
	}
}
