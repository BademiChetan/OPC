#include <stdio.h>
main()
{
int t,len,i,j;
scanf("%d",&t);
scanf("%d",&len);
char ch[len+1],c;
scanf("%s",ch);
int q,a[t],b[t],count[len],k,p=0;
for(i=0;i<len;i++)
count[i] = 0;
scanf("%d",&q);
for(i=0;i<q;i++)
{
scanf("%d",&a[i]);
scanf("%d",&b[i]);
}
for(i=0;i<q;i++)
{
c = ch[a[i]];
for(j =0;j<len;j++)
{
if(ch[j] == c)
{
for(k = 0;k<(b[i]);k++)
{
if(ch[k+j] != ch[(a[i]+k)])
break;
else if(k == b[i]-1)
{
count[p]++;
}
}
}
}
p++;
}
for(i=0;i<p;i++)
printf("%d\n",count[i]);
}




