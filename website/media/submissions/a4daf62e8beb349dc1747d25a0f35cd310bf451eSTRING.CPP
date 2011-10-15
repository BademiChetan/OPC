#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>

void main()
{
clrscr();
long int n;
int a,b,i,x,y,t,m,k,q,count,flag=0;
char ch,ch1,ch2;
cout<<"\n test";
cin>>t;
while(t--!=0)
{
char str[5000]="";
cout<<"\n limit";
cin>>n;
cout<<"\n string";
gets(str);
cout<<"\n queries ";
cin>>q;
while(q--!=0)
{
char substr[5000]="";
cout<<"\n substring";
cin>>m>>k;
count=0;
if(m>n||m+k-1>n)
cout<<"\n wrong input ";
else
{
for(i=m;i<=m+k-1;i++)
 substr[i-m] = str[i];
puts(substr);
for(i=0;str[i]!='\0';i++)
{
flag=0;
for(x=0;x<=k-1&&flag==0;x++)
{
a = substr[x];
b = str[i+x];
if(a!=b)
flag=1;
}
if(flag==0)
count++;
}
cout<<"\n"<<count;
}
}
}
getch();
}