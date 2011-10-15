#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    double N;
    double K;
}point;

void main()
{
    int T,j=0,i;
    double N,K,x,y;
    double rem,rem1;
    int res;
    scanf("%d",&T);
    point *array=(point *)malloc(T*sizeof(point));
    for(i=0;i<T;i++)
    {
        scanf("%lf",&(array[i].N));
        scanf("%lf",&(array[i].K));
    }

    while(T-->0)
    {
        N=array[j].N;
        K=array[j].K;
        res=2%(int)K;
        rem=res;
        rem1=rem;
        for(i=0;i<N;i++){

            rem=fmod((rem*rem),K);

        }
        res=rem;
        printf("%d\n",res);
        j++;
    }
    free(array);
}
