//sg
#include<stdio.h>
#include<list>
#include<algorithm>
#include<iostream>
//#define debug
using namespace std;
list<int> nume,numo;
list<int>::iterator i;
void printe()
{
cout<<"\nEVENS->";
for(i=nume.begin();i!=nume.end();i++)
{
printf("%d-",*i);
}
printf("\n");
}
void printo()
{
cout<<"\nODDS->";
for(i=numo.begin();i!=numo.end();i++)
{
printf("%d-",*i);
}
printf("\n");
}

int play(int n,int * num)
{
//sg
int a,b,temp,e=0,o=0,player=0,t=1;
for(int j=0;j<n;j++)
{
if(num[j]%2==0)
{
e++;
nume.push_back(num[j]);
}
else{
numo.push_back(num[j]);
o++;
}
}
while(1)
{
#ifdef debug
cout<<"Before Turn Number "<<t<<"______________\nEVEN ="<<e<<"\nODD ="<<o<<"\n";
printe();
printo();
#endif
if((e+o)==1)
{
if(e==1)
return 0;
else
return 1;
}
//##########################################################
if(player%2==0) //srinivatsan
{																									
//__________________________________________________________
if(e>=2)
{
i=nume.begin();
a=*i;
nume.pop_front();
i=nume.begin();
b=*i;
nume.pop_front();
e=e-2;
}
else if(o>=2)
{
#ifdef debug
cout<<"HERE AT "<<t;
#endif
i=numo.begin();
a=*i;
numo.pop_front();
i=numo.begin();
b=*i;
numo.pop_front();
o-=2;
}
else //no choice left
{
i=nume.begin();
a=*i;
nume.pop_front();
e--;
i=numo.begin();
b=*i;
numo.pop_front();
o--;
}

//_________________________________________________
temp=a+b-t;
#ifdef debug
cout<<"a="<<a<<"\nb="<<b<<"\nTEMP="<<temp<<"\n";
#endif
if(temp%2==0)
{
nume.push_back(temp);
e++;
}
else
{
numo.push_back(temp);
o++;
}
}//end of srinivatsan's turn
//###########################################
//P's turn,he aims for evens
else
{
if(t%2==0) //so he should make a+b=even
{
if((e>=2))
{
i=nume.begin();
a=*i;
nume.pop_front();
i=nume.begin();
b=*i;
nume.pop_front();
e-=2;
}
else if((o>=2))
{
i=numo.begin();
a=*i;
numo.pop_front();
i=numo.begin();
b=*i;
numo.pop_front();
o-=2;
}
else //no choice left
{
i=nume.begin();
a=*i;
nume.pop_front();
e--;
i=numo.begin();
b=*i;
numo.pop_front();
o--;
}
}
temp=a+b-t;
if(temp%2==0)
{
nume.push_back(temp);
e++;
}
else
{
numo.push_back(temp);
o++;
}
}//end of P's turn
t++;
player++;
}//end of while
//end of function
}
main()
{
int a[100][100];
int t,temp[100],result;
scanf("%d",&t);
for(int i=0;i<t;i++)
{
scanf("%d",&temp[i]);
for(int j=0;j<temp[i];j++)
{
scanf("%d",&a[i][j]);
}
}
for(int i=0;i<t;i++)
{
result=play(temp[i],a[i]);
if(result) //if even left
cout<<"WIN\n";
else
cout<<"LOSE\n";
}
}
