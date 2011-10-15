#include<iostream>

using namespace std;
int main()
{
    int t;int k;int j;
    int i;signed int b=2;;
    long int x[1000][2];
    cin>>t;
    for(i=0;i<t;i++)
    {
                        cin>>x[i][0]>>x[i][1];}
                        for(j=0;j<t;j++)
                       { b=2;for(i=1;i<=x[j][0];i++)
                        {b=b*b;}
                        cout<<(b%x[j][1])<<endl;}
                      
                      } 
