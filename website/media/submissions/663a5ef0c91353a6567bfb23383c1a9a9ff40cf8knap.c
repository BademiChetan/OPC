#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
 
int max_weight;
 
typedef struct { int w, v, qty; } item_t;
 
item_t items[10];
 
/* for C, the main problem is not the algorithm: it's cache management */
int n_types ;
typedef struct {
	int v, w;		   /* value & weight total */
	int n[3]; /* num of each item taken */
} solution_t, *solution;
 
solution_t *cache, *blank;
 
int init_cache()
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
 
	/*  only happens if there are no solution at all, i.e.
	 *  max_weight too small to hold even one item
	 */
	if (ret->v <= 0) return blank;
 
	ret->w = best->w + w * ret->n[pos];
	memcpy(ret->n, best->n, sizeof(int) * pos);
 
	return ret;
}

int main()
{
	int testcases;
	scanf("%d", &testcases);
	while(testcases--){
		//int n_types, max_weight;
		scanf("%d %d", &n_types, &max_weight);
		int i;
		solution x;
		int j=0;
		for (;j<n_types;j++){
			scanf("%d %d %d", &(items[j].w), &(items[j].v), &(items[j].qty));
		}
		/*
		for(j=0;j<n_types;j++){
			printf("%d %d %d\n", (items[j].w), (items[j].v), (items[j].qty));
		}
		*/
		init_cache();
		x = solve(max_weight, n_types - 1);
		
		int max_value = 0;
		//printf("Taking:\n");
		/*
		for (i = 0; i < n_types; i++) {
			if (! x->n[i]) continue;
			//printf("  %hu %s\n", x->n[i], items[i].name);
			max_value += (x->n[i] * items[i].v);
		}
	    */
		//printf("Weight: %d Value: %d\n", x->w, x->v);
		printf("%d\n", x->v);
	}
	/* free(cache); */
	return 0;
}
