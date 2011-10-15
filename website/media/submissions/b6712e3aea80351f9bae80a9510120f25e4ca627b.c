#include <stdio.h>

int main(){
	int t,i;
	int res[101];
	scanf("%d",&t);
	for(i = 0; i < t ;i++ ){
		int n;
		scanf("%d", &n);
		int sum = 0;
		int temp, j;
		for(j = 0; j < n; j++){
			scanf("%d",&temp);
			if( temp%2 == 1) sum++;
		}
		sum += (n%4)/2;
		res[i] = sum%2;
	}
	for ( i = 0; i < t; i++){
		if(res[i] == 0) printf("LOSE\n");
		else printf("WIN\n");
	}
	
	return 0;
}

		
