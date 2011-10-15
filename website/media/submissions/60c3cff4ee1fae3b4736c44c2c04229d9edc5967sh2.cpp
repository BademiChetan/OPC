#include <iostream>
using namespace std;

int main()
{
  int T;
  cin>>T;
  int* a = new int[T];
  for(int i=0;i<T;i++)
  {
    int sum=0;
    int N;
    cin>>N;
    for(int j=0;j<N;j++)
    {
      int k;
      cin>>k;
      sum+=k;
    }
    a[i]=sum-(N*(N-1)/2);
  }
  for(int i=0;i<T;i++)
  {
    if(a[i]%2==0)
    {
      cout<<"LOSE"<<endl;
    }
    else
    {
      cout<<"WIN"<<endl;
    }
  }
  return 0;
}
  
      

