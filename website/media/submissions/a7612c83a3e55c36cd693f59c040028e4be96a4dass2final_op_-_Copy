		//Program for String Manipulcation
#include<stdio.h>
#include<conio.h>
#define ERROR if(str[0]=='\0')\
							printf("\nenter the input first");
void menu();

//functions without pointer
void input(char[]);
void display(char[]);
int lengh(char[]);
void copy(char[],char[]);
int pallindrome(char []);
void concat(char [],char []);     //prototype defination
int compare(char []);
void reverse(char []);
int substring(char []);

//functions with pointer
void pinput(char *);
void pdisplay(char *);
int plength(char *);
void pcopy(char *,char *);
int ppallindrome(char *);
void pconcat(char *,char *);
int pcompare(char *);
void preverse(char *);
int psubstring(char*);

enum result
{
	mgsl=1,sgml,sgma,mgsa,eq
};
void main()
{
	char ch;
	do
	{
		clrscr();
		printf("\n\n\t\t\tSTRING MANIPULATION\n");
		printf("\n\t\t\tMAIN MENU\n");
		printf("\n\t\t\t1. Without Using Pointer");
		printf("\n\t\t\t2. Using Pointer");
		printf("\n\t\t\t3. Exit\n");
		printf("\n\t\t\tEnter your choice: ");
		flushall();
		scanf("%c",&ch);
		switch(ch)
		{
			case '1':
				menu(0);
				break;
			case '2':
				menu(1);
				break;
			case '3':
				break;
			default :
				printf("\n\t\t\tPlease Enter a valid choice");
				getch();
				break;

		}
	}while(ch!='3');
}
void menu(int ch1)
{
	char mstr[50]={0},sstr[50],ch,str[50];
	int l,p;
	do
	{
		clrscr();
		printf("\n\t\t\t\tSUB MENU\n");
		printf("\n\t\t\t1. Input");
		printf("\n\t\t\t2. Display");
		printf("\n\t\t\t3. Length");
		printf("\n\t\t\t4. Copy");
		printf("\n\t\t\t5. Pallindrome");
		printf("\n\t\t\t6. Concatenation");
		printf("\n\t\t\t7. Sub-String");
		printf("\n\t\t\t8. Compare");
		printf("\n\t\t\t9. Reverse");
		printf("\n\t\t\t0. Back to the main menu");
		printf("\n\t\t\tEnter your choice: ");
		flushall();
		scanf("%c",&ch);
		switch(ch)
		{
			case '1':
				clrscr();
				printf("\n\t\t\tINPUT");
				printf("\n\t\t\tPlease input a string: ");
				if(ch1==0)
					input(mstr);
				else
					pinput(mstr);
					break;
			case '2':
				ERROR
				clrscr();
				printf("\n\t\t\tDISPLAY");
				printf("\n\t\t\tThe string is: ");
				if(ch1==0)
					display(mstr);
				else
					pdisplay(mstr);
				break;
			case '3':
				ERROR
				clrscr();
				printf("\n\t\t\tLENGTH");
				printf("\n\t\t\tThe main string is: ");
				display(mstr);
				l=ch='0'?length(mstr):plength(mstr);
				printf("\n\n\t\t\tThe Length of the string = %d",l);
				break;
			case '4':
				ERROR
				clrscr();
				printf("\n\t\t\tThe main string is: ");
				display(mstr);
				if(ch1==0)
					copy(mstr,sstr);
				else
					pcopy(mstr,sstr);
				 printf("\n\n\t\t\tThe copied string is: ");
				 pdisplay(sstr);
				break;
			case '5':
				ERROR
				clrscr();
				printf("\n\t\t\tThe main string is: ");
				display(mstr);
				p=ch='1'?pallindrome(mstr):ppallindrome(mstr);
				if(p==0)
					printf("\n\t\t\tPALLINDROME");
				else
					printf("\n\t\t\tNOT PALLINDROME");
				break;
			case '6':
				ERROR
				clrscr();
				printf("\n\t\t\tThe main string is: ");
				display(mstr);
				if(ch1==0)
					concat(mstr,str);
				else
					pconcat(mstr,str);
				printf("\n\n");
				display(str);
				break;
			case '7':
				clrscr();
				p=ch='0'?substring(mstr):psubstring(str);
				printf("\n\nsub string occures %d times",p);
				break;
			case '8':
				ERROR
				clrscr();
				printf("\n\t\t\tThe main string is: ");
				display(mstr);
				l=ch='0'?compare(mstr):pcompare(mstr);
				if(l==eq)
					printf("\n\n\t\t\tBoth strings are equal");
				else if(l==mgsl)
					printf("\n\n\t\t\tFirst string is greater by length");
				else if(l==sgml)
					printf("\n\n\t\t\tSecond string is greater by length");
				else if(l==mgsa)
					printf("\n\n\t\t\tFirst is greater by ASCII value");
				else
					printf("\n\n\t\t\tSecond is greater by ASCII value");
				break;
			case '9':
				clrscr();
				if(ch1==0)
					reverse(mstr);
				else
					preverse(mstr);
				display(mstr);
				break;
			case '0':
				printf("\n\t\t\tBack to the main menu");
				break;
			default :
				printf("\n\t\t\tPlease Enter a valid choice");
				break;
		}
		getch();
	}while(ch!='0');
}

//functions without pointer begins
//input without pointer
void input(char str[])
{
	int i=-1;
	while(1)
	{
		flushall();
		str[++i]=getche();
		if(str[i]=='\r')
			break;
		if(str[i]=='\b')
		{
			i=i-2;
			if(i<-1)
			{
				i=-1;
				printf(" ");
			}
		 }
		 printf(" \b");
	}
	str[i]='\0';
}

//display without pointer
void display(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
		printf("%c",str[i]);
}

//length without pointer
int length(char str[])
{
	int a,b=0;
	for(a=0;str[a]!='\0';a++)
		b++;
	return(b);
}

//copy without pointer
void copy(char str[],char mstr[])
{

	int a;
	for(a=0;str[a]!='\0';a++)
	   mstr[a]=str[a];
	mstr[a]='\0';
}

//pallindrome without pointer
int pallindrome(char str[])
{
	int a,l=length(str);
	for(a=0;a<l;a++)
	{
		if(str[a]!=str[--l])
			return 1;
	}
	return 0;
}

//concatination without pointer
void concat(char mstr[],char str[])
{
	char sstr[50];
	int a,b;
	printf("\n\t\tPlease enter another string to concate : ");
	input(sstr);
	for(b=0;mstr[b]!='\0';b++)
	{
		str[b]=mstr[b];
	}
	for(a=0;sstr[a]!='\0';a++)
		str[b++]=sstr[a];
	str[b]='\0';

}
//compare without pointer
int compare(char str[])
{
	int l1,l2,a,b;
	char sstr[50];
	printf("\n\t\tPlease enter string to compare : ");
	input(sstr);
	l1=length(str);
	l2=length(sstr);
	if(l1>l2)
		return mgsl;
	if(l2>l1)
		return sgml;
	for(a=0;str[a]!='\0';a++)
	{
		if(sstr[a]>str[a])
			return sgma;
		if(str[a]>sstr[a])
			return mgsa;
	}
	return eq;
}

//reverse without pointer
void reverse(char str[])
{
	int a,l=length(str)-1;
	char b;

	for(a=0;a<l;a++)
	{
		b=str[a];
		str[a]=str[l];
		str[l]=b;
		l--;
	}
}

//sub string without pointer
int substring(char str[])
{
	char sstr[50];
	int a,b,c=0;
	printf("\n\t\tPlease enter substring : ");
	input(sstr);
	for(a=0;str[a]!='\0';a++)
	{
		for(b=0;sstr[b]!='\0';b++)
		{
			if(str[a+b]!=sstr[b])
				break;
		}
		if(sstr[b]=='\0')
			c++;
	}
	return c;
}//functions without pointer ends

//functions with pointer begins
//input with pointer
void pinput(char *str)
{
	int i=-1;
	flushall();
	while(1)
	{
		*(str+(++i))=getche();
		if(*(str+i)=='\r')
			break;
		if(*(str+i)=='\b')
		{
			i=i-2;
			if(i<-1)
			{
				i=-1;
				printf(" ");
			}
		}
			printf(" \b");
	}
	*(str+i)='\0';

}
//display with pointer
void pdisplay(char *str)
{
	int i;
	for(i=0;*(str+i)!='\0';i++)
	{
		printf("%c",*(str+i));
	}
}
//length with pointer
int plength(char *str)
{
	int a,b=0;
	for(a=0;*(str+a)!='\0';a++)
		b++;
	return(b);
}
//copy with pointer
void pcopy(char *mstr,char *sstr)
{

	int a;
	for(a=0;*(mstr+a)!='\0';a++)
		*(sstr+a)=*(mstr+a);
   *(sstr+a)='\0';
}
//pallindrome with pointer
int ppallindrome(char *str)
{
	int a,b;
	for(a=0,b=plength(str);a<b;a++)
	{
		if(*(str+a)!=*(str+(--b)))
				return 1;
	}
	return 0;
}
//concat with pointer
void pconcat(char *mstr,char *str)
{
	char *sstr;
	int a,b;
	printf("\n\t\tPlease enter another string : ");
	input(sstr);
	for(b=0;*(mstr+b)!='\0';b++)
	{
		*(str+b)=*(mstr+b);
	}
	for(a=0;*(sstr+a)!='\0';a++)
		*(str+(b++))=*(sstr+a);
	*(str+b)='\0';
}

//compare with pointer
int pcompare(char *str)
{
	int l1,l2,a,b,c;
	char *sstr;
	printf("\n\t\tPlease enter string to compare : ");
	input(sstr);
	l1=length(str);
	l2=length(sstr);
	if(l1>l2)
		a=mgsl;
	if(l2>l1)
		a=sgml;
	if(l1==l2)
	{
		for(a=0;*(str+a)!='\0';a++)
		{
			if(*(sstr+a)==*(str+a))
				b=a;
			if(*(sstr+a)>*(str+a))
			{
				a=sgma;
				break;
			}
			if(*(str+a)>*(sstr+a))
			{
				a=mgsa;
				break;
			}
		}
		if((b+1)==l1)
		{
			a=eq;
		}
	}
	return a;
}
//reverse with pointer
void preverse(char *mstr)
{
	int a,l=length(mstr)-1;
	char b;
	for(a=0;a<l;a++)
	{
		b=*(mstr+a);
		*(mstr+a)=*(mstr+l);
		*(mstr+l)=b;
		l--;
	}
}
//substring with pointer
int psubstring(char *str)
{
	char *sstr;
	int a,b,c=0;
	input(sstr);
	for(a=0;*(str+a)!='\0';a++)
	{
		for(b=0;*(sstr+b)!='\0';b++)
		{
			if(*(str+a+b)!=*(sstr+b))
				break;
		}
		if(*(sstr+b)=='\0')
			c++;
	}
	return c;
}
/* Made by Naresh Rathore  */