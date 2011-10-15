#include<stdio.h>
#define MAX(x,y) (x<y)?y:x
void preBmBc(char *x, int m, int bmBc[]) {
   int i;
 
   for (i = 0; i < m; ++i)
      bmBc[i] = m;
   for (i = 0; i < m - 1; ++i)
      bmBc[x[i]] = m - i - 1;
}
 
 
void suffixes(char *x, int m, int *suff) {
   int f, g, i;
 
   suff[m - 1] = m;
   g = m - 1;
   for (i = m - 2; i >= 0; --i) {
      if (i > g && suff[i + m - 1 - f] < i - g)
         suff[i] = suff[i + m - 1 - f];
      else {
         if (i < g)
            g = i;
         f = i;
         while (g >= 0 && x[g] == x[g + m - 1 - f])
            --g;
         suff[i] = f - g;
      }
   }
}
 
void preBmGs(char *x, int m, int bmGs[]) {
   int i, j, suff[m];
 
   suffixes(x, m, suff);
 
   for (i = 0; i < m; ++i)
      bmGs[i] = m;
   j = 0;
   for (i = m - 1; i >= 0; --i)
      if (suff[i] == i + 1)
         for (; j < m - 1 - i; ++j)
            if (bmGs[j] == m)
               bmGs[j] = m - 1 - i;
   for (i = 0; i <= m - 2; ++i)
      bmGs[m - 1 - suff[i]] = m - 1 - i;
}
 
 
int BM(char *x, int m, char *y, int n) {
   int i, j, bmGs[n], bmBc[n],count=0;
 
   /* Preprocessing */
   preBmGs(x, m, bmGs);
   preBmBc(x, m, bmBc);
 
   /* Searching */
   j = 0;
   while (j <= n - m) {
      for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
      if (i < 0) {
         count ++;
         j += bmGs[0];
      }
      else
         j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
   }
	return count;
}

int main()
{
	int t,n,q,m,k,i,count,j;
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
			j=0;
			for(i=0;(m+i)<k;i++)
				qstr[i]=inpstr[m+i];
			qstr[i]='\0';
			if(k!=1)
				count = BM(qstr,k,inpstr,n);
			else
				for(j=0;j<n;j++)
					if(inpstr[j]==qstr[0])
						count++;
			printf("%d\n",count);
		}
		
	}
	return 0;
}
