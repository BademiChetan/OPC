//Program for Perform SET Operation
#include<stdio.h>
#include<conio.h>
int input(int[],int);
void display(int[],int,int);
int uni(int[],int[],int,int,int[]);                   //Prototype Declaration
int inter(int[],int[],int,int,int[]);
int difference(int[],int[],int,int,int[]);
int symdiffer(int[],int[],int,int,int[]);
void main()
{                                                      //Starting of main function
	int set1[50],set2[50],set3[100],ch,sch,size1=0,size2=0,size3;
	do
	{
		clrscr();
		printf("\n\n\t\t\t\tSET OPERTIONS");
		printf("\n\n\t\tMenu\n");
		printf("\n\t\t1. Input");
		printf("\n\t\t2. Display");
		printf("\n\t\t3. Union");
		printf("\n\t\t4. Intersection");
		printf("\n\t\t5. Difference ");
		printf("\n\t\t6. Symmetric Difference");
		printf("\n\t\t7. EXIT");
		printf("\n\t\t\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				do
				{
					clrscr();
					printf("\n\t\t\t Input Menu\n");
					printf("\n\t\t1. Set 1\n");
					printf("\n\t\t2. Set 2\n");
					printf("\n\t\t3. Back to the Main Menu");
					printf("\n\t\t\tEnter your choice : ");
					scanf("%d",&sch);
					switch(sch)
					{
						case 1:
							size1=input(set1,1);
							break;
						case 2:
							size2=input(set2,2);
							break;
						case 3:
							printf("\t\t\tGoing Back to the main menu");
							break;
						default:
							printf("Please enter a valid choice");
							getch();
					}
				}while(sch!=3);
				break;
			case 2:
				do
				{
					clrscr();
					printf("\n\t\t\t Display Menu\n");
					printf("\n\t\t1. Set 1\n");
					printf("\n\t\t2. Set 2\n");
					printf("\n\t\t3. Back to the Main Menu");
					printf("\n\t\t\tEnter your choice : ");
					scanf("%d",&sch);
					switch(sch)
					{
						case 1:
							display(set1,size1,1);
							break;
						case 2:
							display(set2,size2,2);
							break;
						case 3:
							printf("\n\t\t\tGoing Back to the main menu");
							break;
						default:
							printf("Please enter a valid choice");
					}
					getch();
				}while(sch!=3);
				break;
			case 3:
				if(size1==0 && size2==0)
				{
					printf("\t\t\tPlease enter the sets to perform union operation");
					getch();
					break;
				}
				printf("\n\t\t\tUnion Operation");
				size3=uni(set1,set2,size1,size2,set3);
				display(set1,size1,1);
				display(set2,size2,2);
				display(set3,size3,3);
				getch();
				break;
			case 4:
				if(size1==0||size2==0)
				{
					printf("Please enter both sets");
					getch();
					break;
				}
				printf("\n\t\t\tIntersection Operation");
				size3=inter(set1,set2,size1,size2,set3);
				display(set1,size1,1);
				display(set2,size2,2);
				display(set3,size3,3);
				getch();
				break;
			case 5:
				do
				{
					clrscr();
					printf("\n\t\t\t Difference Menu\n");
					printf("\n\t\t1. Set 1-Set 2\n");
					printf("\n\t\t2. Set 2-Set 1\n");
					printf("\n\t\t3. Back to the Main Menu");
					printf("\n\t\t\tEnter your choice : ");
					scanf("%d",&sch);

					switch(sch)
					{
						case 1:
							if(size1==0)
							{
								printf("\t\t\tPlease input set1 to perform set1-set2");
								getch();
								break;
							}
							printf("\n\t\t\tDisplaying Set 1-Set 2");
							size3=difference(set1,set2,size1,size2,set3);
							display(set1,size1,1);
							display(set2,size2,2);
							display(set3,size3,3);
							getch();
							break;
						case 2:
							if(size2==0)
							{
								printf("\t\t\tPlease input set2 to perform set2-set1");
								getch();
								break;
							}
							printf("\n\t\t\tDisplaying Set 2-Set 1");
							size3=difference(set2,set1,size2,size1,set3);
							display(set1,size1,1);
							display(set2,size2,2);
							display(set3,size3,3);
							getch();
							break;

						case 3:
							printf("\n\t\t\t Going back to main menu");
							getch();
							break;
						default:
							printf("Please enter a valid choice");
							getch();
					}
				}while(sch!=3);
				break;
			case 6:
				if(size1==0 || size2==0)
				{
					printf("\t\tPlease enter the sets to perform symmetric difference operation");
					getch();
					break;
				}
				printf("\n\t\t\tSymmetric Difference Operation");
				size3=symdiffer(set1,set2,size1,size2,set3);
				display(set1,size1,1);
				display(set2,size2,2);
				display(set3,size3,3);
				getch();
				break;

			case 7:
				break;
			default:
				printf("\n\t\t\tPlease enter a valid choice");
				getch();
		}
	}while(ch!=7);           //End of main function
}
int input(int set[],int sno)
{
	int size,i,j;
	printf("\n\n\t\t\tEnter the number of elements of the set %d : ",sno );
	scanf("%d",&size);
	printf("\n\t\t\tPlease enter %d elements of the set%d:\n ",size,sno);
	for(i=0;i<size;i++)
	{
		printf("\t\t\t");
		scanf("%d",&set[i]);
		for(j=0;j<i-1;j++)
			if(set[j]==set[i])
			{
				printf("\t\tElements should not be repeated,please enter the element again");
				i--;
				break;
			}
	 }
	 return(size);
}
void display(int set[],int size,int sno)
{
	int i;
	printf("\n\t\t\tSet%d={ ",sno);
	for(i=0;i<size-1;i++)
		printf("%d,",set[i]);
	if(size==0)
		printf("}");
	else
		printf("%d }",set[i]);
}
int uni(int set1[],int set2[],int size1,int size2,int set3[])
{
	int i,j,size3;
	for(size3=0;size3<size1;size3++)
		set3[size3]=set1[size3];
	for(j=0;j<size2;j++)
	{
		for(i=0;i<size1;i++)
			if(set2[j]==set1[i])
				break;
		if(i==size1)
			set3[size3++]=set2[j];
	}
	return size3;
}
int inter(int set1[],int set2[],int size1,int size2,int set3[])
{
	int size3=0,i,j;
	for(i=0;i<size1;i++)
		for(j=0;j<size2;j++)
			if(set1[i]==set2[j])
			{
				set3[size3++]=set1[i];
				break;
			}
	return size3;
}
int difference(int set1[],int set2[],int size1,int size2,int set3[])
{
	int size3=0,i,j;
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
			if(set1[i]==set2[j])
				break;
		if(j==size2)
			set3[size3++]=set1[i];
	}
	return size3;
}
int symdiffer(int set1[],int set2[],int size1,int size2, int set3[])
{
	int size3;
	size3=difference(set1,set2,size1,size2,set3);
	size3+=difference(set2,set1,size2,size1,set3+size3);
	return size3;
}
//made by Naresh Rathore