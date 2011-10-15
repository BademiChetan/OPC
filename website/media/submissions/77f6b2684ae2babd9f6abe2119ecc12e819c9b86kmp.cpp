#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
void calpre(string s,int a[])
{
        int n=s.length();
        int j=0;
        int i=1;
        a[0]=0;
        while(i<n)
        {
            if(s[i]==s[j])
            {
                a[i]=j+1;
                j++;
                i++;
            }
            else if(j>0)
            j=a[j-1];
            else
            {
                a[i]=0;
                i++;
            }
        }
}
int kmp(string s,string p)
{
    int i,j;
    int n=s.size();
    int m=p.size();
    int a[p.size()+1];
    calpre(p,a);
    i=0,j=0;
    int ans=0;
    while(i<n)
    {
        if(s[i]==p[j])
        {
            if(j==m-1)
            {
                ans++;
                //cout<<i<<endl;
                i=i-j+1;
                j=0;
            }
            else
            {
                i++;j++;
            }
        }else if(j>0)
        j=a[j-1];
        else
        i++;
    }
    return ans;
}
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        int k;
        scanf("%d",&k);
        while(k--){
        int a,b;
        scanf("%d%d",&a,&b);
        string p=s.substr(a,b);
        printf("%d\n",kmp(s,p));
        }
    }
}
