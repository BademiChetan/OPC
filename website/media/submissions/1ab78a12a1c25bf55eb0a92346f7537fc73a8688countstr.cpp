#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
main()
{
      int t,len,nq;
      cin>>t;
      cin>>len;
      string s;
      cin>>s;
      cin>>nq;
      while(nq--)
      {
                 int i,j=0,l,flag=1;
                 char str[50000];
                 int m,k,z;
                 cin>>m>>k;
                 for(i=m;i<m+k;i++)
                        str[j++]=s[i];
                 str[j]='\0';
                 //cout<<str;
                 
                 int count=0;
                 if(k==1)
                 {
                         count=0;
                         for(i=0;i<len;i++)
                           if(s[i]==str[0])
                             count++;
                 }
                 else
                 {        
                  for(i=0;i<=len-k;i++)
                   {
                     l=i;
                     for(j=0;j<k;j++)
                      {
                        if(s[l++]==str[j])
                          continue;
                        break;                        
                      }
                      if(l==i+k)
                        count++;
                   }
                 }
                   cout<<count<<endl;
                                    
      }
}
