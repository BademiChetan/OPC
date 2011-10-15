#include<iostream>
#include<string>
using namespace std;

int main()
{
  int i,t,n,q,m,k,j,pos,an[50000],x=0,l;
  char s[50000],ch[50000];
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n;
    cin>>s;
    s[n]='\0';
    cin>>q;
    for(j=0;j<q;j++)
    {
      cin>>m>>k;
      for(l=0;l<k;l++)
      {
	ch[l]=s[l+m];
      }
      ch[l]='\0';
      an[x]=0;
      pos=-1;
     for(pos=0;pos+k<=n;pos++)
     {
       if(ch[0]==s[pos])
       {
	 for(l=1;(ch[l]==s[pos+l])&&(l<k);l++);
	 if(l==k)
	 {
	   ++an[x];
	   pos=pos+l-1;
	 }
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