#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t;
   // scanf("%d",&t);
   cin>>t;
    do
    {
      long int n,k;
      long p=1;
      //scanf("%ld%ld",&n,&k);
      cin>>n>>k;
    /*  //long long int p=(n<<2)%k;
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
                   
             */
        //     for(int q=1;q<=n;q++)
      //   {
       //      ans=(ans%k)*(ans%k);   
             
       //  }   
             long b=pow(2,n);
           long a1 = 2 %k;
           p = 1;
             while (b > 0) {
     if (b%2==1) {
         p *= a1;
         p = p % k;
     }
     b /= 2;
     a1 = (a1 * a1) % k;
     }  
         
         
         
         
         
         
             
       cout<<p;            
    t--;
    }while(t!=0);
    
   // getch();
 
    return 0;
}
