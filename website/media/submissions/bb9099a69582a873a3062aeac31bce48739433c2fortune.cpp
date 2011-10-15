#include<iostream>
#include<math.h>
using namespace std;
main()
{
      int cases;
      int n,k,i,temp;
      cin>>cases;
      while(cases--)
      {
                    temp=2;
                    cin>>n>>k;
                    temp*=n;
                    temp=(int)pow(temp,2);
                    cout<<temp%k<<"\n";
      }
      //getchar();
     // getchar();
      return 0;
}     
                    
