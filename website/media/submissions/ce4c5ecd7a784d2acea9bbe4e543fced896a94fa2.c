#include<stdio.h>
int main(){
	int t,n,sum,i,tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&tmp);
			sum+=tmp;
			sum-=i;
		}
		if(sum%2!=0)
			printf("WIN\n");
			else
			printf("LOSE\n");
	}
	return 0;
}
