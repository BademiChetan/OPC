#include <algorithm>
#include <cstdio>
#include <memory.h>



using namespace std;




#define FOR(i,a,b) for(int i=a;i<b;i++)

struct item {
	int w,v;
	int f;
};


int item_cmp(const void *aa, const void *bb)
{
	const struct item *a = (item*) aa, *b = (item*) bb;
	double ua = (double) a->v / (double) a->w, ub = (double) b->v / (double) b->w;
	return ua < ub ? -1 : ua > ub;
}

int main() {
   int N,t,W;
   scanf("%d",&t);
   while(t--) {
   		scanf("%d %d",&N,&W);
		struct item *it;
		int Weight[N], Value[N], F[N];
		struct item items[N];
		int K = 0;
		FOR(i,0,N) {
			scanf("%d %d %d",&Weight[i],&Value[i],&F[i]);
			items[i].w = Weight[i];
			items[i].v = Value[i];
			items[i].f = F[i];
			K += F[i];
		}
		qsort(items, N, sizeof(struct item), item_cmp);
		int a=N-1;
		int ans = 0;
		for(it = items+N-1;W>0,a>=0;){
			if((it->w)>W) {
				it--;
				a--;
				continue;
			}
			W -= it->w;
			ans += it->v;
			it->f -= 1;
			if((it->f)==0) {
				it--;
				a--;
			}
			
			//printf("%d %d %d\n",it->w,it->v,it->f);
		}
		printf("%d\n",ans);




	}
    return 0;
}

