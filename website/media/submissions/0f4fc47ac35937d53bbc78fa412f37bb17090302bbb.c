#include<stdio.h>
int main()
  {
    int t,k,n,j,cnt,i=0,l,m=0,sum, ar[10],h;
     int a[100],T,N,K,d;
     printf("enter  test cases T:");
     scanf("%d\n",&T);
      t=T;
      for(i=1;i<=t;i++){
   scanf("%d %d",&n,&k); 
    cnt=1;
    sum=0;
    for(j=1;j<=n;j++){
       for(l=j;l<=n;l++){
       sum=sum+l;
        if(sum%k==0)
         { cnt++; }
                  } 
                }
  ar[m]=cnt; 
  m++ ;      
        }
   
for(h=0;h<t;h++){
 d=ar[h]+1;

 printf("output = %d\n",d);}
}
         
