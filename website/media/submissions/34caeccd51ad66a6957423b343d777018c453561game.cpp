#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  int tcase; scanf("%d",&tcase);
  while(tcase--){
     int n; scanf("%d",&n);
     int sm = 0;
     for(int i=1;i<=n;++i){
       int x; scanf("%d",&x); sm += x;
     }
     sm -= ((n-1)*n)/2;
     if(sm%2==1) printf("WIN\n");
     else printf("LOSE\n");

  }
  return 0;
}

