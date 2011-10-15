#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
 

 
typedef struct { char *name; int w, v, qty; } item_t;
 

 
/* for C, the main problem is not the algorithm: it's cache management */

typedef struct {
	int v, w;		   /* value & weight total */
	unsigned short n[10000]; /* num of each item taken */
} solution_t, *solution;
 
solution_t *cache, *blank; 
 
int init_cache(int max_weight,int n_types)
{
	/* a flat array.  If problem size is large, might be a bad idea;
	 * then again, other caching method face similar issue, too
	 */
	size_t i;
	size_t n_rec = (max_weight + 1) * n_types;
	cache = calloc(sizeof(solution_t), (n_rec + 1));
	if (!cache) return 0;
 
	for (i = 0; i <= n_rec; i++) {
		cache[i].v = -1;  /* value = -1 means cache not used yet */
		cache[i].w = 0;
	}
	(blank = cache + n_rec)->v = 0;
	return 1;
}
 
solution solve(item_t *items,int weight, int pos,int n_types)
{
	int i, w, v, qty;
	solution sol, best = 0, ret;
 
	if (pos < 0) return blank;
 
	ret = &cache[weight * n_types + pos];
	if (ret->v >= 0) return ret;
 
	w   = items[pos].w;
	v   = items[pos].v;
	qty = items[pos].qty;
 
	for (i = 0; i <= qty && weight > 0; i++, weight -= w) {
		sol = solve(items,weight, pos - 1,n_types);
		if (sol->v + i * v <= ret->v) continue;
 
		best = sol;
		ret->v = best->v + v * i;
		ret->n[pos] = i;
	}
 
	/*  only happens if there are no solution at all, i.e.
	 *  max_weight too small to hold even one item
	 */
	if (ret->v <= 0) return blank;
 
	ret->w = best->w + w * ret->n[pos];
	memcpy(ret->n, best->n, sizeof(unsigned short) * pos);
 
	return ret;
}
 
int main()
{
	int p,T,i,N,max_weight;
	scanf("%d",&T);
	for(p=1;p<=T;p++){ 
	solution x;
        scanf("%d",&N);
        scanf("%d",&max_weight);
        item_t *items = (item_t *) malloc(N * sizeof(item_t));
        int j;
        for(j=0;j<=N-1;j++){
	        scanf("%d",&items[j].w);
	        scanf("%d",&items[j].v);
	        scanf("%d",&items[j].qty);
        }
        
	init_cache(max_weight,N);
	x = solve(items,max_weight, N - 1,N);
 
	/*printf("Taking:\n");
	for (i = 0; i < N; i++) {
		if (! x->n[i]) continue;
		printf("  %hu %d\n", x->n[i], i);
	}*/
 
	printf("%d\n",x->v);
        }
	/* free(cache); */
	return 0;
}
