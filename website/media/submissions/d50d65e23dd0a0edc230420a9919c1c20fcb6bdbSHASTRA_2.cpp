#include<cstdio>

int main() {
    int ntc;
    scanf("%d", &ntc);
    while( ntc-- ) {
        int N, nsum = 0;
        scanf("%d", &N);
        for( int i=0; i<N; i++ ) {
            int x;
            scanf("%d", &x);
            nsum += x;
        }
        puts( (nsum%2==0) ? "WIN" : "LOSE");
    }
    return 0;
}
