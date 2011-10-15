#include <stdio.h>

int main() {
  int T;
  int i,j;
  int N;
  int sum;
  int A[200];
  scanf("%d", &T);
  for(i=0;i<T;i++) {
    scanf("%d", &N);
    sum=0;
    for(j=0;j<N;j++) {
      scanf("%d", &A[j]);
      sum=sum+A[j];
    }
    if((sum-(N*(N-1)/2))%2==0) {
      printf("LOSE\n");
    }
    else printf("WIN\n");
  }
  return 0;
}
  
