#include<stdio.h>                                                   /* Incluing I/O Header files */
 int max(int a,int b,int result[][1000]);
int  unused(int a,int b,int m,int result[][1000]);
main()
{
int t,row[1000],z,m,column[1000],result[1000][1000],maxrow,maxcolumn,k,i,j;
char c;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
 scanf("%c",&c);
  scanf("%d %d",&row[i],&column[i]);
 }
 maxrow=row[0];
 maxcolumn=column[0];
 for(i=1;i<t;i++)
 {
  if(row[i]>maxrow)
  maxrow=row[i];
 if(column[i]>maxcolumn)
  maxcolumn=column[i];
 }
 if(maxcolumn>=maxrow)
 k=maxcolumn+1;
 if(maxrow>maxcolumn)
 k=maxrow+1;
 for(i=1;i<=k;i++)
 {
 result[i][1]=i-1;
 result[1][i]=i-1;
 }
 for(i=2;i<=k;i++)
 {
  for(j=2;j<=k;j++)
  {
 m=  max(i,j,result);
 z =  unused(i,j,m,result);
  if(z==-1)
  result[i][j]= m+1;
  else
  result[i][j] = z;
  }
 }
for(i=0;i<t;i++)
printf("%d\n",result[row[i]+1][column[i]+1]);
 }
 int max(int a,int b,int result[][1000])
 {
 int i,j,maxresultcol,maxresultrow;
  maxresultcol=result[1][b];
  maxresultrow=result[a][1];
  for(i=2;i<a;i++)
  {
   if(result[i][b]>maxresultcol)
   maxresultcol=result[i][b];
  }
  for(i=2;i<b;i++)
  {
   if(result[a][i]>maxresultrow)
    maxresultrow=result[a][i];
  }
  if(maxresultrow>=maxresultcol)
  return maxresultrow;
  else
  return maxresultcol;
 }
int  unused(int a,int b,int m,int result[][1000])

 {
 int z,i,x,j;
  for(z=0;z<m;z++)
  {
   x=0;
   j=0;
   for(i=1;i<a;i++)
   {
   if(result[i][b]==z)
     x =x+1;
    }
   for(i=1;i<b;i++)
   {
    if(result[a][i]==z)
   j=j+1;
   }
  if((j==0)&&(x==0))
  {
  return z;
  break;
  }
  }
  return -1;
 }