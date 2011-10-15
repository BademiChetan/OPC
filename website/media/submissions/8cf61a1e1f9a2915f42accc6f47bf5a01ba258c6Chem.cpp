#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
int main()
{
    long int w,n,test,k;
    long W[10],V[10],F[10],W2[150],V2[150];
    std::vector< std::vector< long > > CS;
    
    cin>>test;
    while(test-->0)
    {
    cin>>n>>w;
    for(long i=0;i<n;i++)
    {
            cin>>W[i]>>V[i]>>F[i];
    }
    k=0;
    
    for(long i=0;i<n;i++)
    {
            for(long j=0;j<F[i];j++)
            {
                    W2[k]=W[i];
                    V2[k++]=V[i];
            }
    }
   
    for(long i=0;i<=k;i++)
            CS[i][0]=0;
    for(long i=0;i<=w;i++)
            CS[0][i]=0;       
    
    for(long i=1;i<=k;i++)
    {
            for(long j=1;j<=w;j++)
            {
                    if(j-W2[i-1]<0)
                                   CS[i][j]=CS[i-1][j];
                                   
                    else
                        CS[i][j]=max(CS[i-1][j],CS[i-1][j-W2[i-1]]+V2[i-1]);
                        
            }
    
    }
    cout<<CS[k][w]<<endl;
}
    //for(int i=0;i<k;i++)
      //      cout<<W2[i]<<" "<<V2[i]<<"*";
    getch();
    return 0;
} 
