#include<stdio.h>
int main()
{
    int t,i=0,N,j;
    scanf("%d",&t);
    long int ans[t],K;
    while(i<t)
{
 scanf("%d %ld",&N,&K);
 j=0;
 ans[i]=2;
 while(j++<N)
 ans[i]*=ans[i];
 ans[i]=ans[i]%K;
 i++;
}
i=0;
while(i<t) 
printf("%ld\n",ans[i++]);
return 0;
}

    
