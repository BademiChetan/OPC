#include<iostream>
#define square(x) (x*x)

unsigned long long int power(unsigned long long a,unsigned long long b)
{
         if(b==1)
         return a;
         if(b%2==0)
         return(square(power(a,b/2)));
         else 
         return(a*power(a,b-1));
}
int main()
{
    int t;
   scanf("%d",&t);
    while(t--)
    { int n,k;
    scanf("%d,&d",&n,&k);
    unsigned long long int two=2;
    unsigned long long k2=power(two,n);
    unsigned long long s=power(two,k2);
    printf("%d\n",s%k);
    }
return 0;
}
