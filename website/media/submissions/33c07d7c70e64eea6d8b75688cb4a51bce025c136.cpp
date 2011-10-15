#include<iostream>
#include<string>
using namespace std;

int main()
{
  int i,t,n,q,m,k,j,pos,an[50000],x=0,l;
  char *s,*ch;
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n;
    s=new char(n);
    cin>>s;
    s[n]='\0';
    cin>>q;
    for(j=0;j<q;j++)
    {
      cin>>m>>k;
      ch=new char(k);
      for(l=0;l<k;l++)
      {
	ch[l]=s[l+m];
      }
      ch[l]='\0';
      an[x]=0;
     for(pos=0;pos+k<=n;pos++)
     {
       for(l=0;(ch[l]==s[pos+l])&&(l<k);l++);
	 if(l==k)
	 {
	   ++an[x];
	   pos=pos+l-1;
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