#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main()
{
 char *str, *substr;
 unsigned int T,lstr,s,Q,M,K,out,i,j;
 scanf("%u",&T);
 while(T--)
 {
  scanf("%u",&lstr);
  str = (char*)malloc(lstr+1);
  scanf("%s",str);
  scanf("%u",&Q);
  while(Q--)
  {
   out=0;
   scanf("%u %u",&M,&K);
   substr = (char*)malloc(K+1);
   strncpy(substr,str+M,K);
   substr[K]='\0';
   for(i=0;i<lstr;i++)
   {
    j=0;
    if(str[i]==substr[j])
	{
	 while(j!=K&&i<lstr)
	 {
	  if(str[i++]!=substr[j++])
	   break;
	 }
	 out++;
	 i--;
	}
   }
   printf("%d\n",out);
  }
 }
}
