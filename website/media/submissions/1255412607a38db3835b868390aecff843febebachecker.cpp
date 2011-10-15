#include <stdio.h>
#include <algorithm>

bool compare (long i,long j) { return (i<j); }

int main()
{
    int t, key, n, i=0, cost[10], cnt=0, value[10], items[10];
    long budget, max_val=0;
    int value_ratio[10], tmp;

    scanf("%d", &t);
    while(t--) {
        scanf("%d%ld", &n, &budget);
        for(i=0;i<n;i++) {
            scanf("%d%d%d", &cost[i], &value[i], &items[i]);
            value_ratio[i] = (1000*cost[i] / value[i]);
                    printf("%ld ", value_ratio[i]);
        }

        max_val = 0;
        for (i=0; i< n; i++) {
            key = i;
            for(int j = i+1; j<n;j++) {
                if (value_ratio[key] > value_ratio[j])
                    key = j;
            }
            tmp = value_ratio[i];
            value_ratio[i] = value_ratio[key];
            value_ratio[key] = tmp;
        }

        for (i=0; i<n;i++) {
            printf("%ld ", value_ratio[i]);
            if (budget >= (cost[i] * items[i])) {
                budget -= cost[i] * items[i];
                max_val += items[i] * value[i];
            } else {
                cnt = budget / cost[i];

                budget -= cost[i] * cnt;
                max_val += value[i] * cnt;
            }
        }
        printf("%ld ", max_val);
    }

    return 0;
}
