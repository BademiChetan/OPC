#include <stdio.h>
#include <string.h>
#define SIZE 100
 
int count(char vector[],int nr);
 
int main()
 
{
int i,string_size,x;
char string[SIZE];
printf("Type a text: ");
gets(string);
string_size=strlen(string);
x=count(string,string_size);
printf("Number of words: %d\n",x);
 
return 0;
}
 
int count (char vector[],int nr)
 
{
int gasit=0,i;
for(i=0;i<nr;i++)
{
if(vector[i]>='a' && vector[i]<='z') gasit++;
if(vector[i]>='A' && vector[i]<='Z') gasit++;
}
 
return gasit;
 
}