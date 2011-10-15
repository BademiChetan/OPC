#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <map>



using namespace std;

typedef map<int,int> MI;



#define FOR(i,a,b) for(int i=a;i<b;i++)

MI Knap;
MI KnapP;

int main() {
   int N,t,W;
   scanf("%d",&t);
   while(t--) {
   		scanf("%d %d",&N,&W);
		int Weight[N+1], Value[N+1], F[N+1];
   		int SUM = 0;
		int K = 0;
		FOR(i,1,N+1) {
			scanf("%d %d %d",&Weight[i],&Value[i],&F[i]);	
			K += F[i];
		}

		
//   		int Knap[W+1];
  // 		int KnapP[W+1];

//		memset(KnapP, 0, sizeof(KnapP));

	   int aI = 1; int kuch = 0;

	   for(int j=1;j<=K;j++) {
 			if(j > F[aI] + kuch) {
				aI++;
				kuch += F[aI];
			}
			for(int w=1;w<=W;w++) {
				if(w>=Weight[aI])
				Knap[w] = max(KnapP[w-Weight[aI]]+ Value[aI], KnapP[w]);
				else
				Knap[w] = KnapP[w];
			}
			for(int w=1;w<=W;w++) {
				KnapP[w] = Knap[w];
			}
	   }

/*		for(int j=1;j<=K;j++) {	
			for(int w=1;w<=W;w++) {
				printf("j=%d, w=%d, Value=%d\n",j,w,Knap[w][j]);
			}
		}*/
//	int S1 = Knap[W];
//	int S2 = SUM - S1;
		printf("%d\n",Knap[W]);
	}
    return 0;
}

