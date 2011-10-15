#include<stdio.h>


int main(){
	int i,j,k,l,m,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=0;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			m+=j;
		}
		n--;
		k=(n*(n+1))/2;
		m-=n;
		if(n&1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}
