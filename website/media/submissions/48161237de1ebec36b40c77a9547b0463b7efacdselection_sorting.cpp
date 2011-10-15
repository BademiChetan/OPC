#include<stdio.h>
#include<conio.h>
int main()
{
int a[10],i,j,temp,small=a[0];
printf("enter the elements: ");
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<10;i++)
small=a[i];
{
for(j=i;j<10;j++)
{
if(a[i]>a[j])
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
printf("\t\t\t\tAFTER SORTING\n\n");
for(i=0;i<10;i++)
{
printf("%d  ",a[i]);
}
getch();
}
