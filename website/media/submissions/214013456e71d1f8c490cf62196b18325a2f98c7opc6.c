
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int function(int m, int k, int n, char* str)
{   
    int i,j;
    int sum=0;
    char sel[50000];
    for(i=0;i<k;i++)
    {
        sel[i] = str[m+i];
    }
    for(i=0;i<n-k;i++)
    {
        for(j=0;j<k;j++)
        {
            if(sel[j] != str[m+i+j]) break;
        }
        if(j==k) sum++;
    }   
    return sum; 
}

int main()
{
    long i,j,M,N,Q,K,T;
    long count[50000];
    char str_in[50000],c,d;
    scanf("%ld",&T);
    c=getchar();
    for(j=0;j<T;j++)
    {   
        scanf("%ld",&N);
        d=getchar();
        gets(str_in);
        scanf("%ld",&Q);
        for(i=0;i<Q;i++) 
        {   
            scanf("%ld%ld",&M,&K);
            count[i] = function(M,K,N,str_in);
        }
        for(i=0;i<Q;i++) printf("%ld\n",count[i]);
    }
    return 0;
    
}
