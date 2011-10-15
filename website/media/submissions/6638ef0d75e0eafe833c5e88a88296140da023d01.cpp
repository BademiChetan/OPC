#include <cstdio>

bool DP[105][105][2];		//S menang ga
bool sudah[105][105][2];
inline bool cari(int sisa, int jgenap, bool balik) {
	if (sisa == 1)
		return jgenap == 0;
	if (sudah[sisa][jgenap][balik])
		return DP[sisa][jgenap][balik];
	//printf("%d %d %d\n", sisa, jgenap, balik);
	bool &ret = DP[sisa][jgenap][balik];
	bool lho1, lho2, lho3;
	int jganjil = sisa - jgenap;
	if (balik) {
		if (jgenap >= 2)
			lho1 = cari(sisa-1, jgenap-2, !balik);
		else
			lho1 = false;
		if (jganjil >= 1 && jgenap >= 1)
			lho2 = cari(sisa-1, jgenap, !balik);
		else
			lho2 = false;
		if (jganjil >= 2)
			lho3 = cari(sisa-1, jgenap, !balik);
		else
			lho3 = false;
		if (lho1 || lho2 || lho3)
			ret = true;
		else
			ret = false;
	}
	else {
		if (jgenap >= 2)
			lho1 = cari(sisa-1, jgenap-1, !balik);
		else
			lho1 = true;
		if (jganjil >= 1 && jgenap >= 1)
			lho2 = cari(sisa-1, jgenap - 1, !balik);
		else
			lho2 = true;
		if (jganjil >= 2)
			lho3 = cari(sisa-1, jgenap+1, !balik);
		else
			lho3 = true;
		if (lho1 == false || lho2 == false || lho3 == false)
			ret = false;
		else
			ret = true;
	}
	sudah[sisa][jgenap][balik] = true;
	return ret;
}
inline void solve() {
	int N, i;
	scanf("%d", &N);
	int jgenap = 0;
	for (i = 0; i < N; i++) {
		int lho;
		scanf("%d", &lho);
		if (lho % 2 == 0)
			jgenap++;
	}
	bool lho = cari(N, jgenap, 1);
	if (lho)
		puts("WIN");
	else
		puts("LOSE");
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
