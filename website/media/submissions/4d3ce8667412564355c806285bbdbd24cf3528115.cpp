#include<iostream>
using namespace std;

int main()
{
  int t,i,n,w,wi[10],vi[10],fi[10],xi[10][2],s[10]={0},temp[2],cost=0,x=0,val=0,j,k;
  cin>>t;
  for(i=0;i<t;i++)
  {
    cin>>n>>w;
    for(j=0;j<n;j++)
    {
      cin>>wi[j]>>vi[j]>>fi[j];
      xi[j][0]=vi[j]/wi[j];
      xi[j][1]=j;
    }
    for(j=0;j<n;j++)
    {
      for(k=j;k<n-1;k++)
      {
	if(xi[k][0]>xi[k+1][0])
	{
	  temp[0]=xi[k][0];
	  xi[k][0]=xi[k+1][0];
	  xi[k+1][0]=temp[0];
	  temp[1]=xi[k][1];
	  xi[k][1]=xi[k+1][1];
	  xi[k+1][1]=temp[1];
	}
      }
    }
    cost =0;
    for(j=0;(j<n)&&(cost<w);j++)
    {
      x=xi[j][1];
      if(cost+(wi[x]*fi[x])>w)
      {
	s[i]=s[i] + (((w-cost)/wi[x])*vi[x]);
      }
      else
      {
	s[i]=s[i]+(fi[x]*vi[x]);
      }
    }
  }
  for(i=0;i<t;i++)
    cout<<s[i]<<endl;
  return 0;
}
    
    
    