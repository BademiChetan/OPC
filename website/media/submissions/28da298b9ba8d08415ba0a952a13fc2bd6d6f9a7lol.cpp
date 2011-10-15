#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t;
   // scanf("%d",&t);
   cin>>t;
    do
    {
      long int n,k;
      long ans=2;
      //scanf("%ld%ld",&n,&k);
      cin>>n>>k;
      //long long int p=(n<<2)%k;
     // long long int p;
     // n=n-1;
      if(k==2)
              ans=0;
      else
    //     p=2<<((2<<n)-1);
      //cout<<p;
      {
          for(int q=1;q<=n;q++)
         {
             ans=(ans%k)*(ans%k);   
               // if(ans>k)      
                 //  ans%k;
                 //cout<<ans;
                // getch();
         }     
           
          
                
     }
     
     
      cout<<ans%k;
                   
                   
    t--;
    }while(t!=0);
    
   // getch();
 
    return 0;
}
