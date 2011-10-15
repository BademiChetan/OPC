#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FR(i,a) for(int i = 0; i < a; i++)
#define maxn 50004
#define oo 1000000009

using namespace std;

int n;
char a[maxn];
int tam[maxn],s[maxn],pos[maxn],key[maxn],inv[maxn],lcp[maxn];
int Tree[maxn*4];

void initsuffix() {
	FOR(i,1,256) tam[i] = 0;
	FOR(i,1,n) tam[a[i]]++;
	FOR(i,1,255) tam[i] += tam[i-1];
	DOWN(i,n,1) s[tam[a[i]]--] = i;
	int x = 0;
	pos[0] = 1;
	key[s[1]] = 0;
	FOR(i,2,n) {
		if (a[s[i]] != a[s[i-1]])
		pos[++x] = i;
		key[s[i]] = x;
	}
	
	int h = 1;
	while (h < n) {
		FOR(i,1,n) tam[i] = s[i];
		FOR(i,1,n)
		if (tam[i] > h)
		{
			x = tam[i] - h;
			s[pos[key[x]]++] = x;
		}
		x  = 0;
		pos[0] = 1;
		tam[s[1]] = 0;
		FOR(i,2,n) {
			if (key[s[i-1]] < key[s[i]] || (key[s[i-1]] == key[s[i]] && s[i-1] + h <= n && s[i] + h <= n && key[s[i-1] + h] < key[s[i] + h]))
			pos[++x] = i;
			tam[s[i]] = x;
		}
		FOR(i,1,n) key[i] = tam[i];
		if (x == n-1) break;
		h = h << 1;
	}
}
void initlcp() {
	FOR(i,1,n) inv[s[i]] = i;
	int h = 0,j,x;
	a[n+1] = '@';
	FOR(i,1,n)
	if (inv[i] == 1) lcp[1] = 0;
	else {
		x = inv[i];
		j= s[x-1];
		while (a[i+h] == a[j+h]) h++;
		lcp[x] = h;
		if (h > 0) h--;
	}
}

void Build(int node, int first, int last) {
    if (first == last) {
        Tree[node] = lcp[first];
        return;
    }
    int mid = (first + last) / 2;
    Build(node * 2, first, mid);
    Build(node * 2 + 1, mid + 1, last);
    Tree[node] = min(Tree[node * 2], Tree[node * 2 + 1]);
}
int visit(int node, int first, int last, int dau, int cuoi) {
    if (cuoi < first || dau > last) return oo;
    if (dau <= first && last <= cuoi) return Tree[node];
    int mid = (first + last) / 2;
    return min(visit(node*2,first,mid,dau,cuoi),
               visit(node*2+1,mid+1,last,dau,cuoi));
}
void solve() {
//    FOR(i,1,n) cout << s[i] << " " << lcp[i] << endl;
    
    FOR(i,1,n) pos[s[i]] = i;
//    FOR(i,1,n) cout << pos[i] << " ";
//    cout << endl;

    memset(Tree,0,sizeof(Tree));
        
    Build(1,2,n);
    
    int vt, len, Q;
    scanf("%d",&Q);
    FOR(i,1,Q) {
        scanf("%d%d",&vt,&len);
        vt++;
        vt = pos[vt];
        
        int resLeft = 0, resRight = 0;
        // tim ben phai
        if (vt == n || lcp[vt+1] < len) resRight = vt;
        else {
            int first = vt + 1, last = n, mid;
            do {
                mid = (first + last) / 2;
                if (visit(1,2,n,vt+1,mid) >= len) first = mid;
                else last = mid;
            } while (last - first > 1);
            if (visit(1,2,n,vt+1,last) >= len) resRight = last;
            else resRight = first;
        }
        // tim ben trai
        if (vt == 1 || lcp[vt] < len) resLeft = vt;
        else {
            int first = 2, last = vt, mid;
            do {
                mid = (first + last) / 2;
                if (visit(1,2,n,mid,vt) >= len) last = mid;
                else first = mid;
            } while (last - first > 1);
            if (visit(1,2,n,first,vt) >= len) resLeft = first - 1;
            else resLeft = last - 1;
        }
        
        printf("%d\n",resRight - resLeft + 1);
        
    }
    /*
	long long result = n - s[1] + 1;
	FOR(i,2,n) {
		int u = s[i];
		int v = lcp[i];
		result += n - u + 1 - v;
	}
	cout << result << endl;
	*/
}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int ntest;
	scanf("%d\n",&ntest);
	while (ntest--) {
        scanf("%d\n",&n);
		gets(a);
		n = strlen(a);
		DOWN(i,n,1) a[i] = a[i-1];
//		cout << n << endl;
//		FOR(i,1,n) cout << a[i];
//		cout << endl;	
		initsuffix();
		initlcp();
		solve();
	}
	return 0;
}
