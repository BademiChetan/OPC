#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
int max_weight,n_types;
struct item_t {
	int name1,w,v,qty;
}items[100];

typedef struct {
	int v, w;		   /* value & weight total */
	unsigned short n[100]; /* num of each item taken */
} solution_t, *solution;
 
solution_t *cache, *blank;
 
int init_cache()
{
	size_t i;
	size_t n_rec = (max_weight + 1) * n_types;
	cache = calloc(sizeof(solution_t), (n_rec + 1));
	if (!cache) return 0;
 
	for (i = 0; i <= n_rec; i++) {
		cache[i].v = -1; 
		cache[i].w = 0;
	}
	(blank = cache + n_rec)->v = 0;
	return 1;
}
 
solution solve(int weight, int pos)
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
		sol = solve(weight, pos - 1);
		if (sol->v + i * v <= ret->v) continue;
 
		best = sol;
		ret->v = best->v + v * i;
		ret->n[pos] = i;
	}
	if (ret->v <= 0) return blank;
 
	ret->w = best->w + w * ret->n[pos];
	memcpy(ret->n, best->n, sizeof(unsigned short) * pos);
 
	return ret;
}
 
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int i;
		scanf("%d%d",&n_types,&max_weight);
		for(i=0;i<n_types;i++){
			items[i].name1=i;
			scanf("%d%d%d",&items[i].w,&items[i].v,&items[i].qty);
		}
		solution x;
		init_cache();
		x = solve(max_weight, n_types - 1);
 		printf("%d\n",x->v);
	}
	return 0;
}
