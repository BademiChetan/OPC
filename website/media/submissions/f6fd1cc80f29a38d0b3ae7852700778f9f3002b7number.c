#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void game(int, int*);
int main(){

int t;
scanf("%d\n", &t);

int **p;
p = (int**)malloc(t*sizeof(int*));

int i=0;
int *j = (int*)malloc(t*sizeof(int));
int k=0;

for(i=0; i<t; i++){
    scanf("%d\n",&j[i]);
    p[i] =(int *)malloc(j[i]*sizeof(int));
    for(k=0;k<j[i];k++){
        scanf("%d", &p[i][k] );
    }
}

for(i=0;i<t;i++){

    game(j[i], p[i]);
}
    return 0;

}


void game(int j, int *p){

    int k;
    long int a =0;
    for(k=0;k<j;k++){
        a+=p[k]; 
    }
    
    long int b=a-(j*(j-1)/2);

    if (b%2 ==0)
    {
    printf("LOSE\n");
    }
    else{
    printf("WIN\n");
    }
}
