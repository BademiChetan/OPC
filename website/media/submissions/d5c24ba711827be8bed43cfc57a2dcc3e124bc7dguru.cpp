#include <iostream>
# include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 50003
#define MAXLG 17


struct entry {
	int nr[2], p;
} ;

int P[MAXLG][MAXN], N, i, stp, cnt;

int cmp(struct entry a, struct entry b)
{
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int lcp(int x, int y,int step)
{
    int k, ret = 0;
    if (x == y) return N - x;
    for (k = step - 1; k >= 0 && x < N && y < N; k --)
        if (P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}


int main()
{

int t;
cin>>t;
for( int x = 0;x < t; x ++ )
{
	char A[MAXN];
	int dummy;	
	cin>>dummy;
	int qq;
	getchar();
	for(qq = 0;qq < dummy;qq++ )
	{
		A[qq] = getchar();
	}
	A[qq] = '\0';
	getchar();
	int ind,le;
	for (N = strlen(A), i = 0; i < N; i ++)
		P[0][i] = A[i] - 'a';

	vector <int> sol(N);
	vector <struct entry> L(N);
	for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
	{
		for (i = 0; i < N; i ++)
		{
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L.begin(), L.end(), cmp);
		for (i = 0; i < N; i ++)
		{
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
			sol[i] = L[i].p;
		}
	}
	int step = stp-1;
	int q;
	cin>>q;
	for( int w = 0 ;w < q; w ++ )
	{	
	cin>>ind>>le;
	
	int lb = 0;
	int ub = P[step][ind];
	
	while ( lb < ub )
	{
		int m  = (lb+ub)/2;
		if( lcp(sol[m],ind,step) >= le )
		{
			ub = m;
		}
		else
		{
			lb = m+1;
		}
	}
	int fl = lb;
	
	lb = P[step][ind];
	ub = N-1;
	
	while ( lb < ub )
	{
		int m  = (lb+ub+1)/2;
		if( lcp(sol[m],ind,step) >= le )
		{
			lb = m;
		}
		else
		{
			ub = m-1;
		}
	}
	int fu = lb;

	cout<< fu - fl+1<<endl; 
	}
	L.clear();
}	

	return 0;
}
























