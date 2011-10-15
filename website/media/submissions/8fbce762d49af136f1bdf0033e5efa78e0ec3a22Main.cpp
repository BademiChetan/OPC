//============================================================================
// Name        : Main2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<math.h>

using namespace std;

int q_pow(int a,int b, int k)
{
	int ans=1;
	for(;b;b>>=1)
	{
		ans=(ans*((b&1)?a:1));
		ans=ans%k;
		a=(a*a)%k;
	}
	return ans;
}

int T, N, K;
const int MAX = 10000;
int a[MAX];
int b[MAX];
bool first = true;

int i, j;

int main() {
	cin >> T;
	int round = T;
	for (i = 0; i < MAX; i++) {
		a[i] = i;
		b[i] = 0;
	}

	for (i = 2; i < MAX; i++) {
		if (a[i] != 0) {
			for (j = i * i; j < MAX; j = j + i) {
				a[j] = 0;
			}
		}
	}

	while (round > 0) {
		cin >> N;
		cin >> K;

		first=true;

		int rst1 = 1;

		for (i = 2; i < MAX; i++) {
			if (a[i] != 0 && K % a[i] == 0) {
				if (first) {
					rst1 = rst1 * K - rst1 * K / i;
					first = false;
				} else
					rst1 = rst1 - rst1 / i;
			}
		}



		int rst2 = 1;
		first=true;
		for (i = 2; i < MAX; i++) {
			if (a[i] != 0 && rst1 % a[i] == 0) {
				if (first) {
					rst2 = rst2 * rst1 - rst2 * rst1 / i;
					first = false;
				} else
					rst2 = rst2 - rst2 / i;
			}
		}


		int rst3=N%rst2;

		int l=rst3;
		int rst4=1;

       /*
		while(l>0){
			rst4=rst4*2%K;
			l--;
		}
*/

		rst4=q_pow(2,rst3,K);
		//rst4=pow(2,rst3);
		//rst4=rst4%K;



		int rst5=1;

		//l=rst4;
		//while(l>0){
		//	rst5=rst5*2%K;
		//	l--;
		//}
		rst5=q_pow(2,rst4,K);

		cout<<rst5<<endl;

		round--;
	}


	return 0;
}
