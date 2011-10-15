#include<stdio.h>
main()  
{
	char ch;
	int n,i,T,W;
	int NUM[10][10];
	FILE *fp;
	int count1,count2;

	int count1,count2;
	fp=fopen("input.txt","r");

	fprintf(fp,"%d\n",n); //get T value (test cases)

			if(T>10 || T<1)
			{
			printf("Invalid value for test cases\n");
			return(0);
			}
	// traverse further in file
	count1=T;
	count2=1;

	for(i=0;i<T;i++)
	{
		fprintf(fp,"%d %d",n,W);
		if(n>10||n<1)
		{ printf("Invalid input for test case %d",count2); return(0); }
     
	}

	fclose(fp);
	return(0);

}