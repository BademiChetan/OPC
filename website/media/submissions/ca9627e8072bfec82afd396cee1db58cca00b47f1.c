#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
 

 
typedef struct { char *name; long long int w, v; int qty; } item_t;
 

 
/* for C, the main problem is not the algorithm: it's cache management */

typedef struct {
	long long int v, w;		   /* value & weight total */
	unsigned short n[20]; /* num of each item taken */
} solution_t, *solution;
 
solution_t *cache, *blank;
 
int init_cache(long long int max_weight,long long int n_types)
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
 
solution solve(item_t items[],int weight, int pos)
{
//printf("sdfsdfj");
   int i;
      
     
    int w, v, qty;
	solution sol, best = 0, ret;
 
	if (pos < 0) return blank;
 
	ret = &cache[weight * (pos+1) + pos];
	if (ret->v >= 0) return ret;
 
	w   = items[pos].w;
	v   = items[pos].v;
	qty = items[pos].qty;
 
	for (i = 0; i <= qty && weight > 0; i++, weight -= w) {
		sol = solve(items,weight, pos - 1);
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
	solution x;
 
	
	long long int max_weight;
	
	long long int n_types;
int t;
scanf("%d",&t);
while(t--)
{
	scanf("%Ld%Ld",&n_types,&max_weight);
	//printf("%Ld%Ld",max_weight,n_types);
	init_cache(max_weight,n_types);

item_t items[20];
   // printf("%d",pos);
    for(i=0;i<n_types;i++)
    {
        //strcpy(items[i].name,"a");   
        scanf("%Ld%Ld%d", &items[i].w,&items[i].v,&items[i].qty);
        //printf("\n%Ld%Ld%d", items[i].w,items[i].v,items[i].qty);
    } 		
x = solve(items,max_weight, n_types - 1);
 
printf("%Ld\n", x->v);
}
	/* free(cache); */
	return 0;
}
