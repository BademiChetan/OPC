#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int s=0;
		for ( int i=0;i<n;++i){
			int a;
			scanf("%d",&a);
			s+=a;
		}
		
		int m= (n*(n-1))/2;
		s-=m;
		s=abs(s);
		if (s&1)printf("WIN\n");
		else printf("LOSE\n");
			
			
	}
return 0;
}
