#include<stdio.h>
unsigned long long int modulo(int a,unsigned long long int b,unsigned long long int c){
    unsigned long long int x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

int main(){
    int t;
    unsigned long long int n,k,i=1;
    scanf("%d",&t);
    while(t--){
               scanf("%ld%ld",&n,&k);
	       i=1;
               while(n!=0){
                          i*=2;n--;
                          }
	       printf("%ld\n",modulo(2,i,k));
               }
    return 0;
}
