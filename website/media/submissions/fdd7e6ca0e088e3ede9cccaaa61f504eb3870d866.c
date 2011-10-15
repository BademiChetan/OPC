#include <string.h>
#include <stdio.h>

#define ALPHABET_SIZE 128
 int count = 0;
 char buf[50005];
char temp[50005];
 int kmp(char *ptr_i,char *ptr_m,int word_length,int sentence_length);
int kmp_table(char *ptr_i,char *ptr_m,int word_length,int sentence_length);
char T[500005];
kmp(char *ptr_i,char *ptr_m,int word_length,int sentence_length)
{
int pos,m=0,i=0;
for(;m<sentence_length; )
{
if(*(ptr_i+i) == *(ptr_m+m+i))
{
i=i+1;
if(i==word_length)
{
pos=m+1;
count++;
}
 
}
else
{
 
m=m+i-T[i];
if(i>0)
i=T[i];
 
}
}
 
return sentence_length;
}
 
 
kmp_table(char *ptr_i,char *ptr_m,int word_length,int sentence_length)
{
int i,j;
i=2;
j=0;
T[0]=-1;
T[1]=0;
for(;i<word_length; )
{
if(*(ptr_i+i-1) == *(ptr_i+j))
{
T[i]=j+1;
i=i+1;
j=j+1;
}
 
else if(j>0)
{
j=T[j];
}
 
else
{
T[i]=0;
i=i+1;
}
}
 
 
}
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",buf);
        int i;
        scanf("%d",&i);
        while(i--)
        {
            int m,l;
            scanf("%d%d",&m,&l);
            strncpy(temp,buf+m,l);
            temp[l]='\0';
           // printf("%s\n",temp);
            count=0;
            kmp_table(temp,buf,strlen(temp),strlen(buf));
            kmp(temp,buf,strlen(temp),strlen(buf));
            printf("%d\n",count);               
        }
    }
        return 0;
}
