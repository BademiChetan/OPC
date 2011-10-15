#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int power(int);
  int T;
  cin>>T;
  int* a=new int[2*T];
  int* b=new int[T];
  int j=0;
  
  for(int i=0;i<2*T;i++)
  {
    cin>>a[i];
  }
  
  for(int i=0;i<2*T;i+=2)
  {
    int m=a[i]%a[i+1];
    b[j]=power(m);
    j++;
  }
  for(int i=0;i<j;i++)
  {
    cout<<b[i]<<endl;
  }
  return 0;
}
    
int power(int m)
{
  int k=2;
  for(int i=0;i<m;i++)
  {
    k=k*k;
  }
  return k;
}   
