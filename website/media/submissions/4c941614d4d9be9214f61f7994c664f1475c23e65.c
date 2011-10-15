#include<stdio.h>
int main()
{
float tc,w,ans=0,curbal=0,list[10][4],big,temp;int i=0,j,l,store,n,m;
scanf("%f",&tc);
for(m=0;m<tc;m++)
{
scanf("%d%f",&n,&w);
for(l=0;l<n;l++)
{
scanf("%f%f%f",&list[l][0],&list[l][1],&list[l][2]);
list[l][3]=list[l][1]/list[l][0];
//printf("%f ",list[l][3]);
}
for(i=0;i<n;i++)
{big=list[0][3];store=0;
for(j=0;j<n-i;j++)
{if(list[j][3]>big){big=list[j][3];store=j;}
}
for(l=0;l<4;l++)
{temp=list[n-i-1][l];
list[n-i-1][l]=list[store][l];
list[store][l]=temp;}
}
for(l=n-1;l>=0;l--)
{//printf("%f% f\n",list[l][0],list[l][3]);
if(list[l][0]<w-curbal)
 {if(list[l][0]*list[l][2]>w-curbal)
    {ans+=(int)((w-curbal)/list[l][0])*list[l][1];
	curbal=curbal+(int)((w-curbal)/list[l][0])*list[l][0];}
else curbal+=list[l][0]*list[l][2];ans+=list[l][1]*list[l][2];
}
}
printf("%f\n",ans);
}
return 0;
}
