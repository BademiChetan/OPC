#include <stdio.h>

int main(){
	int t;
	long int x[10001], y[10001];
	scanf("%d",&t);	
	int i;
	for(i = 0; i < t; i++){
		scanf("%ld %ld",x+i, y+i);
	}
	
	for(i = 0; i < t; i++){
		if (x[i] == 0){
			printf("%ld\n",y[i]);
		}
		else{
			if((y[i]/x[i])%2 == 0)
				printf("%ld\n", (y[i]/x[i] + 1)*x[i] + y[i]%x[i]);
			else
				printf("%ld\n", (y[i]/x[i] - 1)*x[i] + y[i]%x[i]);
		}
	}
}
