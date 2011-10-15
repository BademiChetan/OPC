#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int T,N,K,i,j;
long x;
cout<<" Enter No. of Test Cases:"<<endl;
cin>>T;
for(i=1;i<=T;i++)
{   cout<<"Enter 2 numbers with a space between them"<<endl;
    cin>>N>>K;

    x=2;
    for(j=1;j<=N%K;j++)
	x=pow(x,2);
    cout<<x<<endl;
}
getch();
}