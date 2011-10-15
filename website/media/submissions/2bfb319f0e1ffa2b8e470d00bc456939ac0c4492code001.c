#include<stdio.h>
int main()
{
int n,t,m[50000],k[50000],q,i,j,count=0,counter=0;
char str[50000];
scanf("%d",&t);
while(t)
{
scanf("%d",&n);
scanf("%s",str);        
scanf("%d",&q);
for(i=0;i<q;i++)
 scanf("%d %d",&m[i],&k[i]);
for(i=0;i<q;i++)
 {
  for(j=0;j<n;j++)
   {
    if(str[j]==str[m[i]+counter])
    {
     counter++;
     if(counter==k[i])
       {
        count++;
        counter=0;
        j=j-k[i]+1;
       }
   }               
   } 
  printf("%d",count);
  if(i!=q-1)
   printf("\n");
  count=0;    
  counter=0;          
 }
t--;        
}
return 0;
}
