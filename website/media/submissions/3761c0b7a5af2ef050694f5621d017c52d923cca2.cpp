#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	
	while(T--) {
		int N, s, x;
		
		scanf("%d", &N);
		if ((N%4)==0 || ((N+1)%4)==0) s=0;
		else s = 1;
		
		while(N--) {
			scanf("%d", &x);
			s += x;
		}
		
		if(s%2 == 0) printf("LOSE\n");
		else printf("WIN\n");
	}
}