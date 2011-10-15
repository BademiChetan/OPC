#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
      int t;
      scanf("%d",&t);
      int n , a;
      int ans ;
      while(t--){
	    scanf("%d",&n);
	    ans = -1*n*(n-1)/2;
	    for(int i = 0 ; i < n ; i ++ ){
		  scanf("%d",&a);
		  ans += a; 
	    }
	    printf("%s\n",(ans%2?"WIN":"LOSE"));
      }
      return 0;
}
