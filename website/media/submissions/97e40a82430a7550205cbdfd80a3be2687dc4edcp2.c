#include <stdio.h>

int main(){
	int num;
	scanf("%d",&num);
	int result[num];
	int i = 0;
	while(i<num){
		int set;
		scanf("%d",&set);
		int j = 0;
		int sum = 0;
		while(j<set){
			int temp;
			scanf("%d",&temp);
			sum = sum +temp;
			j++;
		}
		result[i] = sum - ((set)*(set-1))/2;
		i++;
	}
	i =0;
	while(i<num){
		if(result[i]%2)
			printf("WIN\n");
		else
			printf("LOSE\n");
		i++;
	}
	return 0;
}

