#include <stdio.h>

typedef struct chemical_t chemical_t;
struct chemical_t
{
    int w; /* cost */
    int v; /* value */
    int f; /* quantity available */

};

typedef struct test_t test_t;
struct test_t
{
    int n; /* number of chemicals */
    int w; /* budget */
    chemical_t chemical[10];
};

int main(int argc, char **argv)
{
    int t; /* number of tests */
    test_t test;
    chemical_t tmp;

    int i, j, k, mincost, value;

    scanf("%d", &t);

    for(i=0; i<t; i++) /* for each test case */
    {
        value = 0;

        scanf("%d %d", &(test.n), &(test.w));

        for(j=0; j<test.n; j++) /* for each chemical */
        {
            scanf("%d %d %d", &(test.chemical[j].w), &(test.chemical[j].v), &(test.chemical[j].f));
        }

        for (j=0; j<test.n; j++)
            if (test.chemical[j].w > mincost)
                mincost = test.chemical[j].w;

        for (j=0; j<test.n; j++)
        {
            for (k=j+1; k<test.n; k++) /* sort by value for money */
            {
                if (((double) test.chemical[j].v)/((double) test.chemical[j].w) < ((double) test.chemical[k].v)/((double) test.chemical[k].w))
                {
                    tmp = test.chemical[j];
                    test.chemical[j] = test.chemical[k];
                    test.chemical[k] = tmp;
                }
            }
        }

        for (j=0; j<test.n; j++)
        {
            if (test.w > test.chemical[j].w)
            {
                if ((test.w / test.chemical[j].w) >= test.chemical[j].f)
                {
                    test.w = test.w - (test.chemical[j].w * test.chemical[j].f);
                    value = value + (test.chemical[j].v * test.chemical[j].f);
                }
                else
                {
                    test.w = test.w - ((test.w / test.chemical[j].w) * test.chemical[j].w); // budget - items we can afford * cost of each
                    value = value + (test.chemical[j].v * (test.chemical[j].w * (test.w / test.chemical[j].w))); // value + items bought * value of each
                }
            }
        }

        printf("%d\n", value);
    }
    /* sorting by chemical.v */

    return 0;
}
