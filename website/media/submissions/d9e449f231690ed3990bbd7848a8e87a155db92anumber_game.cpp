#include <iostream>

using namespace std; 

int main()
{
    int t=1, T, N, a, b, c[100],i, j, k, l, flag,z,y;
    cin >> T;
    while(T>0)
         {
          T--;
          cin >> N;
          for(i=0; i<N; i++)
             cin >> c[i];
          while(N>=1)
             {
                    
              
              cin >> a >> b;
              for(j=0,flag=0,z=0,y=0; j<N; j++)
              {
               if(c[j]==a && !y) 
                 {flag++; y++;}
               if(c[j]==b && !z)
                  {flag++; z++;}    
               }
              if(flag==2)
               {
                for(l=0; l<2; l++)
                for(j=0; j<N; j++)
                if(c[j]==a || c[j]==b)
                   {
                     for(k=j; k<N-1; k++)
                         c[k]=c[k+1];
                     N--;                        
                   }
                 c[++N]=a+b-t;                
                }
          
               t++;       
               
               if(N==1)
                {
                  if(c[0]%2)         
                   cout << " \n\nlose\n\n ";              
                else 
                   cout << "\n\nwins\n\n";     
                   break;        
                }
          }
  }     
x:

     return 0;
}            