#include<iostream>
#include<cstdio>
#include<string.h>
 
int kmp(char *ptr_i,char *ptr_m,int word_length,int sentence_length);
int kmp_table(char *ptr_i,char *ptr_m,int word_length,int sentence_length);
char T[50000];
 
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--){
                   int N;
                   scanf("%d",&N);
                   char sentence[N];
                   char *ptr_m;
                   ptr_m=sentence;
                   scanf("%s",&sentence);
                   //for(int i=0;i<N;i++) printf("%s",sentence[i]);
                   //printf("\n");
                   int sentence_length=N;
                   int Q;
                   scanf("%d",&Q);
                   for(int p=0;p<Q;p++){
                              int M,K;
                              scanf("%d%d",&M,&K);
                              char word[K];
                              for(int i=0;i<K;i++) word[i]=sentence[M+i];
                              int word_length=K;
                              char *ptr_i;
                              ptr_i=word;
                              //printf("OK\n");
                              kmp_table(ptr_i,ptr_m,word_length,sentence_length);
                              int c=kmp(ptr_i,ptr_m,word_length,sentence_length);
                              printf("%d\n",c);
                   }
    }
    //system("pause");
    return 0;
}
 
int kmp(char *ptr_i,char *ptr_m,int word_length,int sentence_length)
{
  int pos,m=0,i=0,k=0;
  for(;m<sentence_length; )
    {
      if(*(ptr_i+i) == *(ptr_m+m+i))
        {
          i=i+1;
        if(i==word_length)
         {
           pos=m+1;
           k++;
           //printf("The word was found at position %d\n",pos );
         }
        
 
        }
       else
        {
 
         m=m+i-T[i];
         if(i>0)
         i=T[i];
 
        }
    }
    //printf("The word was found %d times\n",k);
 
      return k;
}
 
 
int kmp_table(char *ptr_i,char *ptr_m,int word_length,int sentence_length)
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
