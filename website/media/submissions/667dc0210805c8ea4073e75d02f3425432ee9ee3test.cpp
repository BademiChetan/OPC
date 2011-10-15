#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> p;
typedef vector<p> VP;

#define PB push_back
#define SS ({int taking;scanf("%d", &taking);taking;})

int main()
{
	int t;t=SS;
	while(t--)
	{
		int n;n=SS;int sum=n*(n-1)/2;sum=-sum;
		while(n--)
		{
			int num;num=SS;
			sum+=num;
						
		}
		if(sum&1)printf("WIN\n");
		else printf("LOSE\n");
	}
	
	return 0;
}
