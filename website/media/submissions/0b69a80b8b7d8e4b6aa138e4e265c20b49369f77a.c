#include <stdio.h>

int main(){
	int t;
	int x[1000001], y[1000001];
	scanf("%d",&t);	
	int i;
	for(i = 0; i < t; i++){
		scanf("%d %d",x+i, y+i);
	}
	
	for(i = 0; i < t; i++){
		if (x[i] == 0){
			printf("%d\n",y[i]);
		}
		else{
			if((y[i]/x[i])%2 == 0)
				printf("%d\n", (y[i]/x[i] + 1)*x[i] + y[i]%x[i]);
			else
				printf("%d\n", (y[i]/x[i] - 1)*x[i] + y[i]%x[i]);
		}
	}
}
