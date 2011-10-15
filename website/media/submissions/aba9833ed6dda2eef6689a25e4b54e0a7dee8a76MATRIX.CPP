#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int x[8][8],y[8][8],z[8][8],m,n,p,q,k,i,j;
cout<<"Enter the no raw & column of matrix A:\n";
cin>>m>>n;
cout<<"Enter the matrix of A:\n";
for(i=0;i<m;i++)
  {
  for(j=0;j<n;j++)
  cin>>x[i][j];
  }
cout<<"Enter the no raw and column of matrix B:\n";
cin>>p>>q;
cout<<"Enter the matix of B:\n";
for(i=0;i<p;i++)
  {
  for(j=0;j<q;j++)
  cin>>y[i][j];
  }
  if(n==p)
  {
for(i=0;i<m;i++)
  {
  for(j=0;j<q;j++)
    {                          //TO MULTIPLY TWO MATRIX//
    z[i][j]=0;
    {
       for(k=0;k<n;k++)
       z[i][j]+= x[i][k]*y[k][j];
       }
     }
    }
    cout<<"Resultent matrix is:\n";
    for(i=0;i<m;i++)
    {
    for(j=0;j<q;j++)
    cout<<z[i][j]<<"  ";
    cout<<"\n";
    }
    }
    else
    cout<<"Matrix cannot be added";
    getch();
    }

