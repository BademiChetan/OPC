#include<stdio.h>
#define F(x){ if(x==0) printf("WIN\n"); else printf("LOSE\n"); }
int N,x,s,i,j,k;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        s=0;
        for(i=0;i<N;i++){
            scanf("%d",&x);
            s+=x;
        }
        k=s-(N*(N-1))/2;
        j=-1;
        if(N & 1){
            if(k & 1) F(0)
            else F(1)
        }
        else{
            if(k & 1) F(0)
            else F(1)
        }
    }
    return 0;
}
