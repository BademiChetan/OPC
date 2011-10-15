#include <stdio.h>
#include <math.h>


int main(){
	int num ;
	scanf("%d",&num);
	int i = 0;
	int result[num];
	while(i<num){
		int n,k;
		scanf("%d %d",&n,&k);
		int j = 0;
		int pdt = 2;
		while(j<n){
			if(pdt>(k/2))
				pdt = k-pdt;
			pdt = (pdt*pdt)%k;
			j++;
		}
		result[i] = pdt;
		i++;
	}
	i = 0;
	while(i<num){
		printf("%d\n",result[i]);
		i++;
	}
	return 0;
	
}
