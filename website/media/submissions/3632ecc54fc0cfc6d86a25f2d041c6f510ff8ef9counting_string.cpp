#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int N,c,k,q,m,f;
    string s1,s4;
    while(T--)
    {         
              cin>>N;
              cin>>s1;
              cin>>q;
              while(q--)
              {
                        f=0;
                        c=0;
                        string s2,s3;
                        cin>>m>>k;
                        if(m==k)
                        s2=s1[m];
                        else
                        {for(int i=m;i<m+k;i++)
                        s2+=s1[i];}
                        for(int j=0;j<=N-k+1;j++)
                        {
                                if(s1[j]==s2[0])
                                {
                                                f=1;
                                }
                                if(f==1)
                                {
                                 s3+=s1[j];
                                 if(s3==s2)
                                   {
                                             c++;
                                             f=0;
                                             s3=s4;
                                   } 
                                }
                                else;
                                
                        }
                        cout<<c<<endl;
              }
    }
    
    return 0;
}              
