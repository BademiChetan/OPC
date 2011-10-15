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
#define BLOCK 100

using namespace std;

int n;
char a[maxn];
int tam[maxn],s[maxn],pos[maxn],key[maxn],inv[maxn],lcp[maxn];
int Tree[maxn*4];
int minVal[100000 / BLOCK];

int st[maxn], fn[maxn];
int lab[maxn];

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
void solve() {
//    FOR(i,1,n) cout << s[i] << " " << lcp[i] << endl;
    
    FOR(i,1,n) pos[s[i]] = i;
    
    int nBlock = 1;
    st[nBlock] = fn[nBlock] = 2;
    minVal[nBlock] = lcp[2];
    FOR(i,2,n) {
        lab[i] = nBlock;
        fn[nBlock] = i;
        minVal[nBlock] = min(minVal[nBlock], lcp[i]);
        if (i % BLOCK == 0) {
            nBlock++;
            st[nBlock] = i;
            fn[nBlock] = i;
            minVal[nBlock] = lcp[i];
        }
    }
    int vt, len, Q;
    scanf("%d",&Q);
    FOR(i,1,Q) {
        scanf("%d%d",&vt,&len);
        vt++;
        vt = pos[vt];
        int resLeft = vt, resRight = vt;
        
        int vtBlock = lab[vt];
        // tim ben phai
        bool ok = true;
        FOR(j,vt+1, fn[vtBlock]) 
        if (lcp[j] >= len) {
            resRight = j;
        } else {
            ok = false;
            break;
        }
        
        if (ok) {
            int vitri = vtBlock + 1;
            bool ok2 = true;
            FOR(j,vtBlock+1, nBlock)
            if (minVal[j] >= len) {
                resRight = fn[j];
            } else {
                vitri = j;
                ok2 = false;
                break;
            }
            if (!ok2)
            FOR(j,st[vitri],fn[vitri])
            if (lcp[j] >= len) resRight = j;
            else break;
        }
        
        //tim ben trai
        ok = true;
        DOWN(j,vt,st[vtBlock]) 
        if (lcp[j] >= len) resLeft = j-1;
        else {
            ok = false;
            break;
        }
        if (ok) {
            int vitri = vtBlock - 1;
            bool ok2 = true;
            DOWN(j,vtBlock-1, 1)
            if (minVal[j] >= len) {
                resLeft = st[j]-1;
            } else {
                vitri = j;
                ok2 = false;
                break;
            }
            if (!ok2)
            DOWN(j,fn[vitri],st[vitri]) 
            if (lcp[j] >= len) resLeft = j-1;
            else break;
        }
        printf("%d\n",resRight - resLeft + 1);
    }
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
