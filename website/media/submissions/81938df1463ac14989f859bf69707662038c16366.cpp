#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define REP(i, n) for(int i=0; i<int(n); i++)

// O(n) suffix array construction and LCP computation in O(n) 
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
struct sArray {
	inline bool leq(int a1, int a2, int b1, int b2) { return (a1 < b1 || (a1 == b1 && a2 <= b2)); }
	inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
		return (a1 < b1 || (a1 == b1 && leq(a2,a3,b2,b3)));
	}
	static void radixSort(int *a, int *b, int *r, int n, int alphabetSize) {
		int cnt[alphabetSize + 1], t, sum = 0; memset(cnt,0,sizeof(cnt));	REP (i,n) cnt[r[a[i]]]++;
		REP (i,alphabetSize+1){ t = cnt[i];cnt[i] = sum;sum += t; } REP (i,n) b[cnt[r[a[i]]]++]=a[i];
	}
	void suffixArray(int *s, int *SA, int n, int alphabetSize) {
		int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2, name = 0, c0 = -1, c1 = -1, c2 = -1;
		int s12[n02 + 3], SA12[n02 + 3], s0[n0], SA0[n0];
		s12[n02] = s12[n02+1] = s12[n02+2] = 0;
		SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
		for(int i = 0, j = 0; i < n + n0 - n1; ++i){ if((i % 3) != 0) s12[j++] = i; }
		radixSort(s12, SA12, s+2, n02, alphabetSize);
		radixSort(SA12, s12, s+1, n02, alphabetSize);
		radixSort(s12, SA12, s, n02, alphabetSize);
		REP (i,n02) {
			if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
				name++; c0 = s[SA12[i]]; c1 = s[SA12[i] + 1]; c2 = s[SA12[i] + 2];
			}
			if (SA12[i]%3 == 1) s12[SA12[i]/3] = name;
			else s12[SA12[i]/3 + n0] = name;
		}
		if (name < n02) {
			suffixArray(s12, SA12, n02, name); REP(i,n02) s12[SA12[i]] = i+1;
		} else {
			REP(i,n02) SA12[s12[i] - 1] = i;
		}
		for(int i = 0,j = 0; i < n02; ++i) if(SA12[i] < n0) s0[j++] = 3 * SA12[i];
		radixSort(s0, SA0, s, n0, alphabetSize);
		for(int p = 0, t = n0 - n1, k = 0; k < n; k++){
			int i = GetI(), j = SA0[p];
if(SA12[t]<n0?(leq(s[i],s12[SA12[t]+n0],s[j],s12[j/3])):(leq(s[i],s[i+1],s12[SA12[t]-n0+1],s[j],s[j+1],s12[j/3+n0]))){
				SA[k]=i;t++; if(t == n02) for(k++;p<n0;p++,k++) SA[k] = SA0[p];
			}
			else { SA[k]=j;p++; if(p == n0) for(k++;t<n02;t++,k++) SA[k] = GetI(); }
		}
	}
	void calculateSuffixArray(char *s, int n, int *res) {
		if (n == 1) { res[0] = 0; return; } int _s[n+3];REP(i,n) _s[i]=s[i]; _s[n] = _s[n + 1] = _s[n + 2] = 0;
		suffixArray(_s, res, n, 1000); int ans[n]; REP(i,n) ans[res[i]]=i; REP(i,n) res[i]=ans[i];
	}
 /* LCP[i]=longest common prefix b/w suffixArray[i] and suffixArray[i-1], LCP[0]=0 */
	void calculateLcp(char *s, int n, int *P, int *lcp, int *rank) {
		fill(lcp, lcp + n, 0);
		REP (i,n) rank[P[i]] = i;
		int h=0;
		REP (i,n) {
			if (rank[i] > 0) {
				int j = P[rank[i] - 1];
				while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
				lcp[rank[i]] = h;
				if (h > 0) --h;
			}
		}
	}
};

int N, Q;
char a[50009];

int s[50009], SA[50009], lcp[50009], R[50009], P[50009];

int p_lcp[20][50009];
void calculate_p_lcp() {
	REP(i, N) p_lcp[0][i] = lcp[i];
	for(int j=1; (1<<j) <= N; j++) {
		REP(i, N) p_lcp[j][i] = min(p_lcp[j-1][i], p_lcp[j-1][i+(1<<(j-1))]);
	}
}

int find_lcp(int i, int j) {
	int k = 0;
	while((1<<(k+1)) < (j-i)) k++;
	return min(p_lcp[k][i+1], p_lcp[k][j-(1<<k)+1]);
}

int main() {
	int T; scanf("%d", &T);
	
	while(T--) {
		scanf("%d", &N);
		
		REP(i, N) {
			do scanf("%c", &a[i]); while(a[i]<'a' || a[i]>'z');
			s[i] = a[i] - 'a' + 1;
		}
		
		sArray S;
		S.calculateSuffixArray(a, N, SA);
		//REP(i, N) printf("%d ", SA[i]); printf("\n");
		
		REP(i, N) P[SA[i]] = i;

		S.calculateLcp(a, N, P, lcp, R);
		//REP(i, N) printf("%d ", lcp[i]); printf("\n");

		calculate_p_lcp();
		
		scanf("%d", &Q);
		int m, k;
		while(Q--) {
			scanf("%d%d", &m, &k);
			
			int cur = SA[m], lt, rt;
			//printf("cur= %d\n, m=%d, k=%d", cur, m, k);
			
			int lo = -1, hi = cur, mid;
			while((hi-lo) > 1) {
				mid = (lo + hi)/2;
				if(find_lcp(mid, cur) >= k) hi = mid;
				else lo = mid;
			}
			lt = hi;
			
			lo = cur, hi=N;
			while((hi-lo) > 1) {
				mid  = (lo + hi)/2;
				if(find_lcp(cur, mid) >= k) lo = mid;
				else hi = mid;
			}
			rt = lo;
			
			//printf("lt = %d, rt = %d\n", lt, rt);
			
			printf("%d\n", rt - lt + 1);
		}
		
	}
}

