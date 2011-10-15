#include <cstdio>
int main(){
  int t,a;
  scanf("%d",&t);
  for(int tes=0;tes<t;tes++){
    int n;
    int sume=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      sume+=a;
      if(i!=n-1) sume-=(i+1);
    }
    if(sume<0) sume*=-1;
    if(sume%2==0) printf("LOSE\n");
    else printf("WIN\n");
  }
  return 0;
}
