#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int main()
{
   clrscr();
   int i,j,LB,UB,mid,sval,x[20],n,temp;
   cout<<"\nHow many numbers do you want to enter : ";
   cin>>n;
   cout<<"\nNow enter "<<n<<" numbers ==>\n";
   for(i=0;i<n;i++)
    cin>>x[i];
   cout<<"\nEnter the number to be searched : ";
   cin>>sval;
   for(i=0;i<n-1;i++)
    for(j=0;j<n-1;j++)
     if(x[j]>x[j+1])
     {
       temp=x[j];
       x[j]=x[j+1];
       x[j+1]=temp;
     }
   LB=0,UB=n-1;
   while(LB<=UB)
   {
     mid=(LB+UB)/2;
     if(x[mid]==sval)
       break;
     else
       if(sval<x[mid])
	 UB=mid-1;
       else
	 LB=mid+1;
   }
   if(LB<=UB)
     cout<<"\nNumber "<<sval<<" exist in the list";
   else
    cout<<"\nNumber does not exist ";
   getch();
   return 0;
}
