#include<stdio.h>
#include<stdlib.h>

int sqaure_next_element(int square[1000][1000], int a, int b)
{
    int i, j;
    int allelems[a+b];
    for(i=0; i<b; i++)
        allelems[i] = square[a][i];
    for(j=0; j<a; j++)
        allelems[i+j] = square[j][b];
    
    for(i=0; i<a+b; i++)
    {
        if(search(allelems, i, a+b) == 0)
            continue;
        else
            return i;
    }
    return i;
}

int search(int allelems[], int a, int n)
{
    int i;
    for(i=0; i<n; i++)
        if(a == allelems[i])
            return 0;
    return 1;
}

int main()
{
    int T;
    int X, Y;
    int i;
    int j, k;
    int square[1000][1000];
//  int square[N][N];
//  int big, small;
    
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d %d", &X, &Y);
/*        if(X>Y)
            big = X; small = Y;
        else
            big = Y; small = X; */
        for(j=0; j<=X; j++)
            for(k=0; k<=Y; k++)
                square[j][k] = sqaure_next_element(square, j, k);
        
        printf("%d\n", square[X][Y]);
    }
}
