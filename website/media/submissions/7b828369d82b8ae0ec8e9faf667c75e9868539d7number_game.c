#include<stdio.h>
#include<stdlib.h>

void performTest(){
    int i, val, n, sum = 0;
    scanf( "%d", &n );

    for( i=0; i<n; i++ ){
        scanf( "%d", &val );
        sum += val;
    }

    if( sum%2 == 0 ){
        if( (n - 1)%4 == 1 || (n - 1)%4 == 2 )
            printf( "\nWIN" );
        else
            printf( "\nLOSE" );
    } else {
        if( (n - 1)%4 == 1 || (n - 1)%4 == 2 )
            printf( "\nLOSE" );
        else
            printf( "\nWIN" );
    }
}

int main(){
    int numTest;
    scanf( "%d", &numTest );

    while( numTest-- )
        performTest();
}
