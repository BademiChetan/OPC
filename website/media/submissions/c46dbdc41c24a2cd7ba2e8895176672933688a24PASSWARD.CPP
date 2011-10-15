
#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
long int a,b,i=10,l=6,r=0,j,k,c,f=0;
cout<<"enter a number ";
cin>>a;
b=a;
while (a!=0)
{
  r=a%i;
  a=a/i;
 // cout<<r<<" ";
  ++c;
  };
  cout<<"\n";
  a=b;
  for(j=1;a!=0;++j)
  {
   // gotoxy(3,10);
   // cout<<j;

   r=a%i;
  // cout<<r<<" ";
   a=a/i;
   for(k=0;k<10;++k)
   { f=0;
    gotoxy(12,l);
    if(k==r)
    {
    ++l;
    gotoxy(12,l);
    cout<<k;
    f=1;
    }
   else
    {
    gotoxy(12,l);
    cout<<k;
    }
    if(f==1)
    continue;
    }
    }
  getch();
  }
