#include<stdio.h>
#include<stdlib.h>

#define MAX 100000001L

long rem( long n, long k){
    long long val = (long long)2LL%k, preval, init = val;
    long i, count = 0;

    for( i=2; i<=n; i++ ){

        count++;
        preval = val;
        val = ( val * val )%k;

        if( val == preval )
            return val;

        if( val == init )
            break;

    }

    if( i <= n ){
        n = n%count;
        for( i=2; i<=n; i++ )
            val = ( val*val )%k;
    }


    return (long)val;
}

void performTest(){
    long i, n, k;
    scanf( "%ld %ld", &n, &k );

    printf( "\n%ld", rem( n+1, k ) );

}

int main(){

    int i, numTest;
    scanf( "%d", &numTest );

    while( numTest-- )
        performTest();
    return 0;
}
