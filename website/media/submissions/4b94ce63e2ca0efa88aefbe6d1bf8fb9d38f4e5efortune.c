#include<stdio.h>
#include<stdlib.h>

#define MAX 100000001L

long rem( long n, long k){
    long long val = (long long)2LL%k, init = val;
    long i, count = 0;

    for( i=2; i<=n; i++ ){

        count++;
        val = ( val * val )%k;

        if( val == init )
            break;
        else if( val == 1 || val == 0 )
            break;
    }

    if( val == 1 || val == 0 )
        return val;

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
