
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int function(int m, int k, int n, char* str)
{   
    int i,j;
    int sum=0;
    for(i=0;i<n-k;i++)
    {
        for(j=0;j<k;j++) if(str[m+j] != str[m+i+j]) break;
        if(j==k) sum++;
    }   
    return sum; 
}

int main()
{
    long i,j,M,N,Q,K,T;
    long count[50000];
    char str_in[50000];
    scanf("%ld",&T);
    getchar();
    for(j=0;j<T;j++)
    {   
        scanf("%ld",&N);
        getchar();
        gets(str_in);
        scanf("%ld",&Q);
        for(i=0;i<Q;i++) 
        {   
            scanf("%ld%ld",&M,&K);
            count[i] = function(M,K,N,str_in);
            printf("%ld\n",count[i]);
        }
    }
    
    return 0;
    
}
