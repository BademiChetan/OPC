#include<stdio.h>
int main()
{
   int i,j=0,k,l,s,a[10],T,n,x;
    printf("enter no. of test cases:T");
    scanf("%d",&T);

   for(i=1;i<=T;i++){
	s=2;
     printf("enter  n,k");
     scanf("%d%d",&n,&k);
 
   for(x=1;x<=n;x++){
        s=s*s;}
   a[j]=s%k;     
     j++;      
    
                      }
  for(l=0;l<T;l++){
  printf("output=%d\n",a[l]);}
}
