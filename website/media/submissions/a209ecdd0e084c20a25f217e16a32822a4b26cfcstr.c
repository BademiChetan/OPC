#include<stdio.h>

void getSub(char[],char[]);
main()
{

 	  int totalCases;
 	  //printf("enter total cases\n");
 	  scanf("%d",&totalCases);
while(totalCases>0)
{
	  //printf("enter the length of string\n");
	  int lenStr;
	  scanf("%d",&lenStr);

        char string[(lenStr)+10];
 	    //printf("enter the string..\n");
 	    scanf("%s",string);

 	    int totalSubCases;
 	    //printf("..enter total sub cases\n");
 	    scanf("%d",&totalSubCases);
 	      while(totalSubCases>0)
 	      {
			 int first,lenSb,i;
             //printf(".....enter the first index and length of substring..\n");
             scanf("%d%d",&first,&lenSb);
             int p= lenSb + 10;
		   	char sub[p];
		   	for(i=0;i<lenSb;i++,first++)
		   	   sub[i]=string[first];
		   	   sub[i++]='\0';
		   	  	getSub(string,sub);
          	totalSubCases--;
	      	}



 totalCases--;
 }
	   getch();
	   }
void getSub(char string[],char sub[])
{
 	int lenStr=strlen(string),lenSb=strlen(sub);
 	  int i ,j,k,total=0;
 	 for(i=0;i<lenStr;i++)
 	  {
	   	  if(string[i]==sub[0])
			 {
				int k=i,count=0;
			  	 for(j=0;j<lenSb;j++)
				    {
					  if(string[k++]==sub[j])
						count++;
		             }
				 if(count==lenSb)
					     total++;
		     }

		 }

 	  printf("%d\n",total);





	 }
