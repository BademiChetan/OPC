#include <stdio.h>
#include <math.h>
void main(){
    unsigned int T,N,K,i,j,f=2;
    //double f=2;
    scanf("%u",&T);

    for (i=0; i<T;i++){
        scanf("%u %u",&N,&K);
        for(j=0;j<N;j++){
            f = f % K;
            f = pow(f,2);

        }
        printf("%u",f);
    }
}