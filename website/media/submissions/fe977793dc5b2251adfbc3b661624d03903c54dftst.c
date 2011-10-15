#include <stdio.h>
int powr(int l)
{
int tmp4=1;
if(l%2==0&&(l!=0))
{tmp4=(powr(l/2));
return (tmp4*tmp4);
}
if(l%2!=0&&(l!=0))
{tmp4=(powr((l-1)/2));
return (2*tmp4*tmp4);}
else
{return 1;}
printf("%d \n",tmp4);
}
int main()
{
int T;
int i=0;
int N[100],K[100];
scanf("%d",&T);
while(i<T)
 {scanf("%d %d",&N[i],&K[i]);
 i++;
 }
int j=0;
int tmp,tmp1,tmp2,tmp3;
while(j<T)
{
tmp=powr(N[j]);
tmp2=(powr(tmp));
tmp3=tmp2%K[j];
printf("%d \n",tmp3);
j++;
}
return 0;
}
