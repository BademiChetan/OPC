#include <stdio.h>
main()
{
  int T,k;
  int resd[4][4];
  long x,y,ec,fc,val,e,f;
  scanf("%d",&T);
  k=0;
   
   
   resd[0][0]=0;
   resd[0][1]=1;
   resd[0][2]=2;
   resd[0][3]=3;
   resd[1][0]=1;
   resd[1][1]=0;
   resd[1][2]=3;
   resd[1][3]=2;
   resd[2][0]=2;
   resd[2][1]=3;
   resd[2][2]=0;
   resd[2][3]=1;
   resd[3][0]=3;
   resd[3][1]=2;
   resd[3][2]=1;
   resd[3][3]=0;
   
   while(k!=T)
   {
    scanf("%ld",&x);
    scanf("%ld",&y);
    if(x==y)
    printf("0\n");
    else
    {
    
    e=x%4;
    ec=(x-e)/4;
    f=y%4;
    fc=(y-f)/4;
    if((ec%2)==0 || (fc%2)==0)
    {
     val=ec*4+fc*4;
     val = val + resd[e][f];
     }
     else
     {
      val = ec*4 + fc*4-8;
      val=val + resd[e][f];   
         }
      printf("%ld\n",val);
      }
    
      k=k+1;        
     }
  
      }
