#include<cstdio>
using namespace std;

typedef unsigned int Uint;
Uint K[100000010];
Uint K1[100000010];
Uint weights[160];
Uint values[160];

#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    //freopen("input.txt","r",stdin);
    Uint T,N,W,i,j,k,w,v,f,n,testW,testV;
    scanf("%u",&T);
    while(T--)
    {
        scanf("%u",&N);
        scanf("%u",&W);
        testW = 0;
        testV = 0;
        Uint counter = 1;
        for(i=1;i<=N;i++){
            scanf("%u%u%u",&w,&v,&f);
            testW += (w*f);
            testV += (v*f);
            while(f>0){
                weights[counter] = w;
                values[counter] = v;
                f--;
                counter++;
            }
        }
        if(testW<W){
            printf("%u\n",testV);
        }
        else{
            n = counter-1;
            for(i=0;i<=W;i++)
                K1[i] = 0;
            for(j=1;j<=n;j++){
                for(w=1;w<=W;w++){
                    if(weights[j]>w){
                        K[w] = K1[w];
                    }
                    else{
                        K[w] = max((K1[w]),(K1[(w-weights[j])]+values[j]));

                    }
                }
                for(w=1;w<=W;w++)
                    K1[w] = K[w];
            }
            printf("%u\n",K1[W]);
        }
    }
    return 0;
}
