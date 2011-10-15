#include <iostream>
#include <cstdio>
using namespace std;

int lessthan(int a)
{
	int p=1;
	while(p<a)
		p*=2;
	return p/2;
}

int fun(int a,int b)
{
	int X=max(a,b);
	int Y=min(a,b);
	
	if ( X==Y)
		return 0;
	int val=lessthan(X);
	if ( Y>val)
		return fun(X-val,Y-val);
	
	return ( val+ fun(X-val,Y));
	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		a++;
		b++;
		
		printf( "%d\n",fun(a,b));
		
		
	}
return 0;
}
