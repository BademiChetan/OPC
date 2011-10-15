#include<stdio.h>
main()
{int i,k,l,p,j,t,n,g=0,q,ab[50000][2],c[50000];
for(i=0;i<50000;i++)c[i]=0;
char str[50000];
scanf("%d",&t);
for(i=0;i<t;i++)
 {scanf("%d",&n);getchar();
  gets(str);
  scanf("%d",&q);
  for(j=0;j<q;j++)
   {scanf("%d %d",&ab[j][0],&ab[j][1]);}
   for(k=0;k<q;k++)
   {for(j=0;j<n;j++)
     {if(str[j]==str[ab[k][0]])
        {for(l=0;l<ab[k][1];l++)
           {if(str[j+l]==str[ab[k][0]+l])
             ++g;}
       if(g==ab[k][1])c[k]++;g=0;}}}
    for(j=0;j<q;j++)printf("%d\n",c[j]);}}
