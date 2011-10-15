#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n,w,t1,t2,t3;
            cin>>n>>w;
            int a[n][3];
            for(int j=0;j<n;j++)
            {
                  cin>>a[j][0]>>a[j][1]>>a[j][2];  
            }
            for(int j=0;j<n;j++)
            {
                    for(int k=j+1;k<n;k++)
                    {
                            if(a[k][1]>a[j][1])
                            {
                                    t1=a[j][0];
                                    t2=a[j][1];
                                    t3=a[j][2];
                                    a[j][0]=a[k][0];
                                    a[j][1]=a[k][1];
                                    a[j][2]=a[k][2];
                                    a[k][0]=t1;
                                    a[k][1]=t2;
                                    a[k][2]=t3;          
                            }
                    }
            }
            long long int ans=0;
            for(int j=0;j<n;j++)
            {
                    if(w>=a[j][0]*a[j][2])
                   { ans=ans+a[j][1]*a[j][2];w=w-a[j][0]*a[j][2];}
                   else
                   { ans=ans+(a[j][2]*(w/a[j][0]));w=w-(w/a[j][0]); }
            }
            cout<<ans<<endl;
    }
    return 0;
}
