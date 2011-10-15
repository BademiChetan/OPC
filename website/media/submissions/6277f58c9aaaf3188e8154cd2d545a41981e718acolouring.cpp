#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	int x, y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", x^y);
	}
	return 0;
}
