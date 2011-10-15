#include<iostream>


using namespace std;

int main()
{
    int T,N,K;
    int count,s,s2;
    int c=1;
    int i,j,l;
    
    
    
    cin>>T;
    
    
    for (int a=1; a<=T; a++)
    {
        count=2;
        cin>>N;
    cin>>K;
    
    for (i=1; i<N; i++)
    {
        if (i%K==0)
        count++;
        
        for (j=i+1; j<=N; j++)
        {
            c=1;
            
           for (int z=0; z<=N-j; z++)
           {
               
           s2=(c*j)+(c*(c-1)/2);
            for(l=j+c; l<=N; l++)
            {
                       if ((s2+l+i)%K==0)
                       count++;
                       
                       }
                       c++;
                       }
                       }
                       }
                
    for (int i=1; i<N; i++)
    {
        for (int j=i+1; j<=N; j++)
        {
            if ((i+j)%K==0)
            count++;
            }
            }
    
            
cout<<count<<endl;

}


return 0;
}
