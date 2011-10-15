#include <stdio.h>
#include <math.h>
int powr(int l)
{
int tmp4=1;
if(l%2==0&&(l!=0))
{tmp4=(powr(l/2));
return (tmp4*tmp4);
}
else if(l%2!=0&&(l!=0))
{tmp4=(powr((l-1)/2));
return (2*tmp4*tmp4);}
else
{return 1;}
}
int main()
{
int T,i=0,N[100],K[100];
scanf("%d",&T);
while(i<T)
 {scanf("%d %d",&N[i],&K[i]);
 i++;
 }
int j=0;
int tmp2,tmp3;
while(j<T)
{
tmp2=(powr(powr(N[j])));
//float tmp=exp(log(2)*exp(log(2)*N[j]));
//tmp2=(tmp);
tmp3=tmp2%K[j];
printf("%d \n",tmp3);
j++;
}
return 0;
}
