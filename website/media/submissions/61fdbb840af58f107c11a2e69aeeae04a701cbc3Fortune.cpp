#include<cstdio>
#include<cstdlib>
#include<cmath>

long long unsigned int rem[10000];

main(){
     int t;
     scanf("%d", &t);
     while(t--){
        long long unsigned int n;
        long long unsigned int k;
        scanf("%llu %llu", &n, &k);
        int count = 0;
        long long unsigned int ans = 2;
      int flag1 = 0;
        for( long long unsigned int i = 1; i <=n; i++){
            ans = (ans *ans)%k;
    //        printf("%d %llu\n", count, ans);
    int flag = 0;
            for( int j = 0; j < count; j++){
                if(rem[j] == ans){
                    flag = 1;
                    break;
                }
            }
          if( flag == 1) {
              flag1 = 1;
              break;
          }
          else   rem[count++] = ans;
//            if( ans == 0 || ans == 1)
//                break;
        }
        if( flag1 != 1)
             printf("%llu\n", ans);
        else printf("%llu\n", rem[n%count]);

     }
}
