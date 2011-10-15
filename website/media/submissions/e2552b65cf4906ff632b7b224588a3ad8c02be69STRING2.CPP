#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{
clrscr();
long int n,i,q,k,m;
int a,b,x,t,count,flag=0;
char ch,ch1,ch2;
cout<<"\n test";
cin>>t;
while(t--!=0)
{
char str1[25000]="",str2[25000]="";
cout<<"\n limit";
cin>>n;
if(n>50000)
cout<<"\n maximum limit exceeded";
else
{
cout<<"\n string";
if(n>50000)
cout<<"\n limit exceeded..";
else
{
if(n>25000)
for(i=0;i<n;i++)
cin>>str1[i];
else if(n<50000)
{
for(i=0;i<10;i++)
cin>>str1[i];
for(i=0;i<n-10;i++)
cin>>str2[i];
}
cout<<"\n";
puts(str1);
puts(str2);
cout<<"\n queries ";
cin>>q;
if(q>50000)
cout<<"\n max.. queries exceeded..";
else
while(q--!=0)
{
char substr1[2000]="",substr2[2000]="";
cout<<"\n substring";
cin>>m>>k;
count=0;
if(m>n||m+k-1>n)
cout<<"\n wrong input ";
else
{
if(k>25000)
for(i=m;i<=m+k-1;i++)
if(i<25000)
 substr1[i-m] = str1[i];
 else
 substr1[i-m] = str2[i];
else
for(i=m;i<=m+k-1;i++)
if(i-m<25000)
if(i<25000)
 substr1[i-m] = str1[i];
 else
 substr1[i-m] = str2[i];
else
 substr2[i-m] = str2[i];
puts(substr1);
puts(substr2);
for(i=0;i<n;i++)
{
flag=0;
for(x=0;x<=k-1&&flag==0;x++)
{
if(x<25000)
a = substr1[x];
else
a = substr2[x];
if(i+x<25000)
b = str1[i+x];
else
b = str2[i+x];
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
}}
getch();
}