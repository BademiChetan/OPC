#include<cstdio>
#include<cstdlib>
#include<cmath>

main(){
    int t;
    scanf("%d", &t);
    while( t--){
        int x, y;
        scanf("%d%d", &x, &y);
        int z = abs(x-y);
        printf("%d\n", z);
    }

}
