#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int t,i,j,k,l,m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=0;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			m+=j;
		}
		n--;
		k = (n*(n+1))/2;
		m-=k;
		if(m&1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}

