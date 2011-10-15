#include <iostream>
//#include <conio.h>
using namespace std;
int main()
{
    int w,n,test;
    int W[10],V[10],F[10],W2[150],V2[150],CS[200][200];
    
    cin>>test;
    while(test-->0)
    {
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
            cin>>W[i]>>V[i]>>F[i];
    }
    int k=0;
    
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<F[i];j++)
            {
                    W2[k]=W[i];
                    V2[k++]=V[i];
            }
    }
   
    for(int i=0;i<=k;i++)
            CS[i][0]=0;
    for(int i=0;i<=w;i++)
            CS[0][i]=0;       
    
    for(int i=1;i<=k;i++)
    {
            for(int j=1;j<=w;j++)
            {
                    if(j-W2[i-1]<0)
                                   CS[i][j]=CS[i-1][j];
                                   
                    else
                        CS[i][j]=max(CS[i-1][j],CS[i-1][j-W2[i-1]]+V2[i-1]);
                        
            }
    
    }
    cout<<CS[k][w];
}
    //for(int i=0;i<k;i++)
    //        cout<<W2[i]<<" "<<V2[i]<<"*";
    //getch();
    return 0;
} 
