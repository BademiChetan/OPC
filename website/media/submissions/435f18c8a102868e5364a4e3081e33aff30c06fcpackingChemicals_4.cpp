#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int max_weight = 200;

struct item_t { int w, v, qty; };
item_t *items;
/*item_t items[] = {
	{9,	150,	1},
	{		13,	35,	1},
	{		153,	200,	2},
	{		50,	60,	2},
	{		15,	60,	2},
	{			68,	45,	3},
};
*/
/* for C, the main problem is not the algorithm: it's cache management */
int n_types = 15;
struct solution_t{
	int v, w;		   /* value & weight total */
	unsigned short n[15]; /* num of each item taken */
} *solution;


solution_t *cache, *blank;

int init_cache()
{
	/* a flat array.  If problem size is large, might be a bad idea;
	 * then again, other caching method face similar issue, too
	 */
	size_t i;
	size_t n_rec = (max_weight + 1) * n_types;
	cache = reinterpret_cast<solution_t*>(calloc(sizeof(solution_t), (n_rec + 1)));
	if (!cache) return 0;

	for (i = 0; i <= n_rec; i++) {
		cache[i].v = -1;  /* value = -1 means cache not used yet */
		cache[i].w = 0;
	}
	(blank = cache + n_rec)->v = 0;
	return 1;
}

solution_t* solve(int weight, int pos)
{
	int i, w, v, qty;
	solution_t *sol, *best = NULL, *ret;

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
	memcpy(ret->n, best->n, sizeof(unsigned short) * pos);

	return ret;
}

int main()
{
	int i;
	solution_t *x;
    int testcases,N,W,w,v,f;
    //freopen("input.txt","r",stdin);
    scanf("%d",&testcases);
    while(testcases>0){
    scanf("%d%d",&N,&W);
    max_weight = W;
    items = new item_t[N];
    for(i=0;i<N;i++){
        scanf("%d%d%d",&w,&v,&f);
        item_t newItem;
        newItem.w = w;
        newItem.v = v;
        newItem.qty = f;
        items[i] = newItem;
    }
    n_types = N;
	init_cache();
	x = solve(max_weight, n_types - 1);
    printf("%d\n",x->v);
    testcases--;
    }
	/* free(cache); */
	return 0;
}
