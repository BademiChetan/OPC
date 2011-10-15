#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    long N;
    long K;
}point;

int main()
{
    int T,j=0;
    long N,K,i,rem;
    scanf("%d",&T);
    point *array=malloc(T*sizeof(point));
    for(i=0;i<T;i++)
    {
        scanf("%d",&(array[i].N));
        scanf("%d",&(array[i].K));
    }

    while(T-->0)
    {
        rem=2%K;
        N=array[j].N;
        K=array[j].K;
        for(i=0;i<N;i++)
        {
            rem=(rem*rem)%K;
        }
        printf("%d\n",rem);
        j++;
    }
    free(array);
}
