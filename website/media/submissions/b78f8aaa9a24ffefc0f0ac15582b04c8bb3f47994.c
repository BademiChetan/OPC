#include<stdio.h>

void preKmp(char *x, int m, int kmpNext[]) {
   int i, j;

   i = 0;
   j = kmpNext[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}


int KMP(char *x, int m, char *y, int n) {
   int i, j, kmpNext[m],count=0;

   /* Preprocessing */
   preKmp(x, m, kmpNext);

   /* Searching */
   i = j = 0;
   while (j < n) {
      while ((i > -1 )&& (x[i] != y[j]))
         i = kmpNext[i];
      i++;
      j++;
      if (i >= m) {
         count++;
         i = kmpNext[i];
      }
   }
	return count;
}

int main()
{
	int t,n,q,m,k,i,count;
	char inpstr[50002],qstr[50002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",inpstr);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %d",&m,&k);
			i=0;
			for(i=0;(m+i)<k;i++)
				qstr[i]=inpstr[m+i];
			qstr[i]='\0';
			if(k!=1)
				count = KMP(qstr,k,inpstr,n);
			else
				for(i=0;i<n;i++)
					if(inpstr[i]==qstr[0])
						count++;
			printf("%d\n",count);
		}
		
	}
	return 0;
}
