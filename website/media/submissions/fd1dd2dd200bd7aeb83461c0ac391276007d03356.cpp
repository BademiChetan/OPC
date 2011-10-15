#include<iostream>
#include<string>
using namespace std;

int main()
{
  int i,t,n,q,m,k,j,pos,an[50000],x=0,l;
  char s[50000],ch[50000];
  string s1,ch1;
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n;
    cin>>s;
    s[n]='\0';
    //s1=s;
    cin>>q;
    for(j=0;j<q;j++)
    {
      cin>>m>>k;
      //ch1=s1.substr(m,k);
      for(l=0;l<k;l++)
      {
	ch[l]=s[l+m];
      }
      ch[l]='\0';
      an[x]=0;
      pos=-1;
     /* while(pos+k<n)
      {
	pos=s1.find(ch1,pos+1);
	if(pos==-1)
	  break;
	an[x]++;
      }*/
     for(pos=0;pos+k<=n;pos++)
     {
       if(ch[0]==s[pos])
       {
	 for(l=1;(ch[l]==s[pos+l])&&(l<k);l++);
	 if(l==k)
	   ++an[x];
       }
     }
      x++;
    }
  }
  for(i=0;i<x;i++)
  {
    cout<<an[i]<<endl;
  }
  return 0;
}