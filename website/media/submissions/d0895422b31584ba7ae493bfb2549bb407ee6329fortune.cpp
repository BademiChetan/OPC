#include<iostream.h>
#include<math.h>
main()
{
      int cases;
      int n,k,i,temp;
      cin>>cases;
      while(cases--)
      {
                    temp=2;
                    cin>>n>>k;
                    for(i=1;i<=n;i++)
                    {
                               temp=pow(temp,2);
                    }
                    cout<<temp%k<<"\n";
      }
      //getchar();
     // getchar();
      return 0;
}     
                    
