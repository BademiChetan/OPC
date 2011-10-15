#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int performTest(){
    int X, Y, ind1, ind2;
    scanf( "%d %d", &X, &Y );

    if( Y == 0 )
        return X;

    int interval = 2 * pow( 2, (int)(log( Y )/log( 2 )) );

    ind1 = (X/interval) * interval;
    ind2 = (X/interval + 1) * interval - 1;

    Y %= interval;
    X %= interval;

    while( interval > 1 ){

        interval = interval/2;

        if( Y >= interval ){
            if( X >= interval )
                ind2 = ind2 - interval;
            else
                ind1 = ind1 + interval;
        } else{
            if( X >= interval )
                ind1 = ind1 + interval;
            else
                ind2 = ind2 - interval;
        }
        Y %= interval;
        X %= interval;
    }

    return ind1;
}

int main(){
    int numTest;
    scanf( "%d", &numTest );

    while( numTest-- )
        printf( "\n%d", performTest() );

    return 0;
}
