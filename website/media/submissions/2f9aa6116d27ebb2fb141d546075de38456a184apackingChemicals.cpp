#include<stdio.h>
#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;

typedef unsigned int Uint;
Uint K[1000000][150];
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
            K[i][0] = 0;
        for(i=0;i<=n;i++)
            K[0][i] = 0;
        for(j=1;j<=n;j++)
            for(w=1;w<=W;w++)
                if(weights[j]>w){
                    K[w][j] = K[w][j-1];
                    //cout<<w<<"\t"<<j<<"\t"<<K[w][j]<<endl;
                }
                else{
                    K[w][j] = max((K[w][j-1]),(K[(w-weights[j])][j-1]+values[j]));
                    //cout<<w<<"\t"<<j<<"\t"<<K[w][j]<<"else"<<endl;
                }

        printf("%u\n",K[W][n]);
    }
    return 0;
}
