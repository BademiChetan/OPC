#include<iostream>
using namespace std;
int main()
{
    int t;
   // scanf("%d",&t);
   cin>>t;
    do
    {
      long int n,k;
      //scanf("%ld%ld",&n,&k);
      cin>>n>>k;
      //long long int p=(n<<2)%k;
      long long int p;
      if(k==2)
              p=0;
      else
         p=(2<<((2*n)-1))%k;
      cout<<p;
      
      
                   
                   
    t--;
    }while(t!=0);
    
    
 
    return 0;
}
