#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int power(long long int );
int main(){
int t;
scanf("%d\n", &t);
long long int* n;
long long int* k;

n= (long long int*)malloc(t *sizeof(long long int));
k= (long long int*)malloc(t *sizeof(long long int));
int i=0;
    for(i=0;i<t;i++)
        {
            scanf("%lld %lld", &n[i] ,&k[i]);
        }
    long long int a,b;

    for(i=0;i<t;i++){
        a= power(n[i]+1);
        b= a%k[i];
        printf("%lld \n",b );
    }

return 0;
}

long long int power(long long int a){
    long long int i=0;
    long long int b=2;
    for (i=0; i< a-1; i++){
        b*=b;
    }
    return b;

}
