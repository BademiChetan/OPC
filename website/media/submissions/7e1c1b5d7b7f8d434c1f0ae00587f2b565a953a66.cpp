#include<iostream>
#include<string>
using namespace std;

int main()
{
  int i,t,n,q,m,k,j,an[10][50000]={0},pos,h[10]={0};
  char s[50000];
  string s1,ch1;
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n;
    cin>>s;
    s[n]='\0';
    s1=s;
    cin>>q;
    for(j=0;j<q;j++)
    {
      cin>>m>>k;
      ch1=s1.substr(m,k);
      an[i][j]=0;
      pos=-1;
      while(pos+k<n)
      {
	pos=s1.find(ch1,pos+1);
	if(pos==-1)
	  break;
	an[i][j]++;
      }
    }
    h[i]=j;
  }
  for(i=0;i<t;i++)
  {
    for(j=0;j<h[i];j++)
    {
      cout<<an[i][j]<<endl;
    }
  }
  return 0;
}