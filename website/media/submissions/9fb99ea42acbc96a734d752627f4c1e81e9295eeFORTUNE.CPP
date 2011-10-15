#include <iostream>
using namespace std;

int main()
{
  long int N[1000],K[1000],T,X,temp,res;
  int M;
  cin>>T;
  for(M=0;M<T;M++)
      cin>>N[M]>>K[M];

  for(M=0;M<T;M++)
    {
      temp=N[M]%K[M];
       res=2;
	for(X=0;X<temp;X++)
	 res=res*res;
       cout<<endl<<res;
   }
return 0;
}