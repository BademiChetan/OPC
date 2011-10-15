#include <stdio.h>
int main()
{
    //int n,k
    int t;
    scanf("%d",&t);
    int n[t],k[t],ans[t];
    int i;
    
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n[i],&k[i]);    
    }
    
    for(i=0;i<t;i++)
    {
        switch(k[i])
            {
                case 1:
                case 2:ans[i] = 0;break;
                case 3:if(n[i]>1)
                        {
                        ans[i] = 1;
                        }
                        else
                        {
                        ans[i] = 2;
                        }
                        break;
                case 4:ans[i] = 0;break;
                default:
                ans[i] = 0;
                //printf(" i  \n")
                int b = n[i];
                int a1 = 4;
                int p = 1;
                int m = k[i];
             while (b > 0)
             {
                if (b%2 ==1) {
                    p *= a1;
                    p = p % m;
                              }
                b /= 2;
                a1 = (a1 * a1) % m;
            }

  ans[i] = p;
  break;                     
                
            }
 
  }  

  for(i=0;i<t;i++)
  {
  printf("%d\n",ans[i]);
  }  
    
    return 0;
}
