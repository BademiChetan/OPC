#include<iostream.h>
main()
{
int i,j,T,N,sum=0;
cin>>T;
int c[100];
for(j=0;j<T;j++)
{
cin>>N;
int A[100];
for(i=0;i<N;i++)
{
cin>>A[i];
}
for(i=0;i<N;i++)
{
sum=sum+A[i]-i;
}
if(sum%2==0)
{
c[j]=0;
}
else
{
c[j]=1;
}
}
for(i=0;i<T;i++)
{
if(c[i]==1)
{
cout<<"WIN\n";
}
else
{
cout<<"LOSE\n";
}
}
return 0;
}