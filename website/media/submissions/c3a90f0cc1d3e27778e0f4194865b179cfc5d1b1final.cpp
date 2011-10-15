#include<stdio.h>
#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

typedef unsigned int Uint;
Uint K[100000001];
Uint K1[100000001];
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
    //freopen("input.txt","r",stdin);
    Uint T,N,W,i,j,k,w,v,f,n,testW;
    scanf("%u",&T);
    while(T--)
    {
        scanf("%u",&N);
        scanf("%u",&W);
        vector<Uint> weights;
        vector<Uint> values;
        testW = 0;
        weights.push_back(0);
        values.push_back(0);

        for(i=1;i<=N;i++){
            scanf("%u%u%u",&w,&v,&f);
            testW += (w*f);
            while(f>0){
                weights.push_back(w);
                values.push_back(v);
                f--;
            }
        }
        if(testW<W)
            W = testW;
        n = (Uint)weights.size();
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
    return 0;
}
