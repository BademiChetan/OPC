#include<stdio.h>

int main()
 {
          int t, i;
          long long n, k, result, j;
          
          scanf("%d", &t);
          for(i=0;i<t;i++)
           {
                          scanf("%lld%lld", &n, &k);
                          result=2;
                          
                          for(j=0;j<n;j++)
                                          result=(result*result)%k;
                          printf("%lld\n", result);
           }
          return 0;
 }
