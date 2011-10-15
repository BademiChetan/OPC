#include<cstdio>
#include<cstdlib>
#include<cmath>

main(){
     int t;
     scanf("%d", &t);
     while(t--){
        long long unsigned int n;
        long long unsigned int k;
        scanf("%llu %llu", &n, &k);
        n = n%k;
        long long unsigned int ans = 2;
        for( long long unsigned int i = 1; i <=n; i++){
            ans = (ans *ans)%k;
            if( ans == 0 || ans == 1)
                break;
        }
        printf("%llu\n", ans);

     }
}
