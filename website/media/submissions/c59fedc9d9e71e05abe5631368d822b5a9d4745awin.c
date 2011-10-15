#include<stdio.h>
main()
{
int i,j,T=0,N=0,t=0,a,b,x;
char A[1000][2];
scanf("%d",&T);
scanf("%d",&N);
for(i=0;i<N;i++)
{
scanf("%d",A[i][0]);
scanf("%d",A[i][1]);
}

while(T>0&&T<100)
{
while(N>0&&N<100)
{
x=0;

}
}

while(!x)
{

for(i=0;i<N;i++)
{
a=A[i][0];
b=A[i][1];
t++;
if(!(a+b-t)%2)
printf("WIN");
else
printf("LOSE");
}
}
}