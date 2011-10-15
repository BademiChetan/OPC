#include<stdio.h>

int main() {
    int t, n, tmp, sum=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        sum -= n * (n+1) / 2;
        while (n--) {
            scanf("%d", &tmp);
            sum += tmp;
        }
        printf(sum % 2 ? "WIN\n": "LOSE\n");
    }

    return 0;
}
