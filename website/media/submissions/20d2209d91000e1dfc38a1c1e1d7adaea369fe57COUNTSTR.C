/* Sample input file format in teststr.dat file which is
  INPUT FILE	used in this program for pattern recognition

1
6
abcabc
3
02
03
11           // An external file is being used here.....please note
		       FILE NAME IS: teststr.dat
*/


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
int T,N,Q,a,i,j,M[5],K[5],length,t,count[5],flag;
char str[5],query[5][5];
char *ptr;
FILE *f1;
clrscr();
f1=fopen("teststr.dat","r");

fscanf(f1,"%d",&T);
if(T>10)
{
printf("\n No of test cases exceeded the limit\n");
exit(0);
}

fscanf(f1,"%d",&N);


if(N>50)
{
printf("\n The size of the string is exceeding\n");
exit(0);
}

fscanf(f1,"%s",str);


fscanf(f1,"%d",&Q);
if(Q>50)
{
printf("\n The no of query limit is exceeding. so exiting\n");
exit(0);
}

for(i=0;i<Q;i++)  // scanning the queries in appropriate format
{
fscanf(f1,"%d %d",&M[i],&K[i]);
}

for(i=0;i<Q;i++)          //for every query finding the query string
{
t=M[i];     //index
length=K[i];  //length
ptr=&str[t];
strcpy(query[i],ptr); //only for the first index value of the query
t++;
for(j=1;j<=length;j++)          //extracting the substring of length 'K'
{
	ptr=&str[t];
	strcat(query[i],ptr);
	t++;		//this is the traversing index in the original str
}
}

for(a=0;a<Q;a++)
{
count[a]=0;
for(i=0;i<N;i++)
{
flag=0;
ptr=&str[i];
if(strcmp(ptr,query[a])==0)
{
	for(j=1;j<K[a];j++)
	{
		i++;
		ptr=&str[i];
		if(strcmp(ptr,query[a])!=0)
		{
			flag=1; 	//mis-match
			break;
		}
		if(flag==0 && j==K[a])
		{
		count[a]++;
		}
	}
}
}
printf("\n The number of times the substring occurs in the whole string is %d",count);
}
getch();
fclose(f1);

}











