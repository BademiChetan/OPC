#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
      int t;
      scanf("%d",&t);
      int x , y;
      while(t--){
	    scanf("%d%d",&x,&y);
	    printf("%d\n",x>y?x-y:y-x);
      }
      return 0;
}
