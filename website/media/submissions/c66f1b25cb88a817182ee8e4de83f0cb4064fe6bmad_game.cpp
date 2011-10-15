#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int N,t,T,i,j,a,b;
    cin>>T;
    while(T--)
    {
     cin>>N;
     int p[N];
    for(i=0;i<N;i++)
    {
                    cin>>p[i];
                    
                    
    }
    t=1;
    
    
    for(i=0;i<N;i++)
    {
     for(j=i+1;j<N;j++)
     {
           a=p[i];
           b=p[j];
           p[i]=(a+b)-t;
           if(j!=1)
           p[j]=p[j+1];
           t++;
           }
           }
          
           if((p[i]%2)==0)
           cout<<"\nLOSE\n";
           else
           cout<<"\nWIN\n";
           }
           getch();
           return 0;
           }
           
    
    
