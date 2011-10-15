#include <iostream>

using namespace std;

int main()
{
  int N,T,c[100],s;
  cin >> T;
  while(T>0)
  {
   T--;
   s=0;
   cin >> N;
   for(int i=0; i<N ; i++)
      { 
        cin >> c[i];   
        s+=c[i];   
      }
   if(s%2)
      cout << "win"<<endl;
   else
      cout << "lose"<<endl;
   }
return 0;
}      
