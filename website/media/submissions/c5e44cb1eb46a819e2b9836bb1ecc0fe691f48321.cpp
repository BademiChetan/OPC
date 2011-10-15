
/*Kaushik Iska*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair
#define all(x) (x.begin(),x.end())
#define rep(i,n) for(int i=0;i<n;i++)
#define print(x) cout<<#x<<" is "<<x<<endl;
#define inf 2000000000
#define eps 1e-8

using namespace std;

int main(){
	int nt;
	scanf("%d",&nt);
	while(nt--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int c = a^b;
		printf("%d\n",c);
	}
	return 0;
}
