#include <stdio.h>
unsigned int pow2(unsigned int x)
{ unsigned int r=1;
         while(x--)
          r*=2;
          return r;
}
          
int main()
{int T;
unsigned int n,k,res1,res2,x,rem,result;
scanf("%d",&T);
while(T--)
{
    scanf("%u",&n);   
    scanf("%u",&k);
    res1=1;
     x=n/4;
    rem=n%4;
    while(x--)
     {  
              res1=((res1%k)*(65536%k))%k;
     }
     res2=pow2(pow2(rem))%k;
     result=(res1*res2)%k;
       //result=(res1!=0)?(((res1%k)*(res2%k))%k):(res2%k);
     printf("%u",result);
     }
    return 0;
}
