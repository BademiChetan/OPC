#include<stdio.h>

int main(void){
	int tcase,num,i,curr,sum;
	scanf("%d",&tcase);
	while(tcase--){
		scanf("%d",&num);
		i=num;sum=0;
		while(i--){
			scanf("%d",&curr);
			sum+=curr;
		}
		i=sum-((num*(num-1))/2);
		if(i%2==0){
			printf("LOSE\n");
		}
		if(i%2==1){
			printf("WIN");
		}
	}
	return 0;
}
