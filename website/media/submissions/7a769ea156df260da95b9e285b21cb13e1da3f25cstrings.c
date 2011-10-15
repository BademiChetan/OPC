#include<stdio.h>
#include<malloc.h>

int main()
{
 char *str, *substr,out;
 unsigned int T,lstr,s,Q,M,K,i,j;
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
   j=0;
   for(i=M;i<M+K;i++)
    substr[j++]=str[i];
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
   free(substr);
  }
  free(str);
 }
}
