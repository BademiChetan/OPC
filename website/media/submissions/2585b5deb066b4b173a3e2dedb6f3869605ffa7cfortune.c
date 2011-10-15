#include<stdio.h>
#include<stdlib.h>

long long rem( long long n, long long k){
    if( n == 1 )
        return ( (long long)2LL )%k;

    return ( ( rem( n-1, k )*rem( n-1, k ) )%k );
}

void performTest(){

    long long n, k;
    scanf( "%lld %lld", &n, &k );

    printf( "%lld", rem( n+1, k ) );
}

int main(){
    int numTest;
    scanf( "%d", &numTest );

    while( numTest-- )
        performTest();
    return 0;
}
