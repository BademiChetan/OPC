#include<stdio.h>
int main()
{   int test;
    long long int num,k,ans;
     scanf("%d",&test);
     while(test--)
     {
     scanf("%lld %lld",&num,&k);
    ans=2;
    while(num)
    {ans*=ans%k;
      ans%=k;
     num--;
    }
 printf("%lld\n",ans);
}
//getch();
return(0);

}
