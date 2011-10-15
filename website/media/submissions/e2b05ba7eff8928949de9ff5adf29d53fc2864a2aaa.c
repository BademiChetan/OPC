#include<stdio.h>
int fn(int arr[10]);
int main()

{
	int T,n,a,b,s,i,j,w,N,t=0,arr[10],brr[10];
        printf("enter no. of cases T :\n");
        scanf("%d",&T);
        printf("enter N :");
        scanf("%d",&N);
         printf("now enter integars\n");           
        for(i=1;i<=T;i++)
        {  
           
            for(j=0;j<2;j++)
              {
                scanf("%d",&arr[j]);
                		}
              w = fn(arr);
      if(w%2==0){
       brr[t]=1;
        t++;}
      else {
       brr[t]=0;
        t++;  }
            
      printf("\n");         }
   
 for(s=0;s<t;s++)
 
 if(brr[s]==1)
  
 {  printf("win\n");}
  
  else
     { printf("loss\n");
   } }
       
      
   fn(int arr[10]){
    int i,c;
    for(i=1;;i++)
     {  c=arr[0]+arr[1]-i;
        if(c==arr[0]||c==arr[1])
        return c;}
       }
