//tis is the final one
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

int main()
{
	int t,i,j,k,c,n,a,b;
	cin>>t;             //accepting the no of test cases
	int x[t][2];        //declaing array
	for(i=0;i<t;i++) 
	  for(j=0;j<2;j++)
	    cin>>x[i][j];      //accepting the inputs for test cases
		
	for(k=0;k<t;k++)     //t loop
	{
	  if(x[k][0] > x[k][1])  //comparing the row elements
	n=x[k][0];       //declaring the n square 
	else
	n=x[k][1];
//	cout<<n;

	int y[n+1][n+1];     //array for n *n sqaure
	c=0;	
	for(i=0;i<=n;i++)    //for row loop
	{
	c=i;        //starting valus
   for(j=0;j<=n;j++)   //column loop
   {
     if(i==0)    //
	 {
    y[i][j]=c;
	c++;
	}
	else
	{
	
	if(c<=5)
	     {
		y[i][j]=c;
		c++;
		}
	else
	{
	  c=0;
	  }
	  
	   }
	   
	   }
	   }
        a=x[k][0];
		b=x[k][1];
	//	cout<<a<<b<<endl;
		
	   cout<<y[a][b]<<endl;
	   }
	   getch();
	   return 0;
	   }
	   
