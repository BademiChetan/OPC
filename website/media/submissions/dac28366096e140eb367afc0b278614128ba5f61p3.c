#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    double N;
    double K;
}point;

void main()
{
    int T,j=0,i;
    double N,K;
    double rem;
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
        for(i=0;i<N;i++)
        {
             rem=(rem*rem)-((int)((rem*rem)/K))*K;
             //res=(int)rem;
             //if(rem==res)
             //rem=res;
             //else
             //rem=++res;
        }
        res=rem;
        printf("%d\n",res);
        j++;
    }
    free(array);
}
