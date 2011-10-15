#include<stdio.h>
main()
{
 int a[1000000];
 int i=0,j;
 int k;
 int t;
 int l;
 char c;
 int max,min,upperlimit;
 int row,column;
 scanf("%d",&t);
 int checkrow[t],checkcolumn[t];
 while(i<t)
{
scanf("%c",&c);
scanf("%d",&checkrow[i]);
scanf("%c",&c);
scanf("%d",&checkcolumn[i]);
i++;
}
 for(i=0;i<t;i++)
{
 
  
   upperlimit=(int) (checkrow[i]/4)*4;
   for(k=0;k<=checkcolumn[i];k=k+4)
    {
     
      
      
       
        if(checkrow[i]%4==0)
         {
          a[k]=upperlimit;
          a[k+1]=upperlimit+1;
         a[k+2]=upperlimit+2;
         a[k+3]=upperlimit+3;
          }
        else
          if(checkrow[i]%4==1)
          {
         a[k]=upperlimit+1;
         a[k+1]=upperlimit;
         a[k+2]=upperlimit+3;
         a[k+3]=upperlimit+2;
          }
        else
          if(checkrow[i]%4==2)
          {
        a[k]=upperlimit+2;
         a[k+1]=upperlimit+3;
        a[k+2]=upperlimit;
       a[k+3]=upperlimit+1;
          }
        else
        {
        a[k]=upperlimit+3;
         a[k+1]=upperlimit+2;
        a[k+2]=upperlimit+1;
       a[k+3]=upperlimit;
        }
       
      if(k+3>=checkcolumn[i]){
       printf("colour=%d\n",a[checkcolumn[i]]);
       break;
       }
       min=a[0];
       max=a[0];
      for(l=0;l<=k+3;l++)
       {
        if(a[l]<min)
        min=a[l];
        else
        if(a[l]>max)
        max=a[l];
       printf("\n%d\n%d\n",min,max);
      }
      if(min==0)
      
        upperlimit=max+1;
      else
      upperlimit=a[k-7]-8;
     printf("\n%d\n",upperlimit);
      }
    
  }
  } 

