#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
typedef pair<long long int , int> Pair ; 
int n , total ; 
int cst[12];
int val[12];
int qty[17];
int stat[17];
map<Pair , int> m ; 

long long int func(int budget , int index)
{
	if(index < 0)
		return 0;
	if(budget <= 0)
		return 0;
	if(m[Pair(budget , index)] != 0)
		return m[Pair(budget ,index)] ; 
	int i;
	long long int ans = 0;
	long long int use ;
	for(i = 0 ; i <= stat[index] ; i++)
	{
		stat[index] -= i ;
		use = func(budget - i *cst[index] , index -1) + i*val[index] ;
		stat[index] += i ; 
		if(use > ans)
		{
			ans = use ; 
		}
	}
	m[Pair(budget , index)] = ans ; 
	return ans ; 
}


int main()
{
	int t; 
	int i ;
	long long int ans ; 
	scanf("%d",&t);
	while(t--)
	{
//		memset(dp , -1 , sizeof(dp));
		m.clear();
		scanf("%d%d",&n,&total);
		for(i = 0; i < n; i++)
		{
			scanf("%d%d%d",&cst[i],&val[i],&qty[i]);
			stat[i] = qty[i];
		}
		ans = func(total , n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
