#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int* point(int x)
{
	int *m = malloc(4*2);
	m[0] = (int)log2(x);
	m[1] = pow(2,(double)m[0]);
	//m[2] = x - m[1];
	return m;
}

int val(int x, int y)
{
	
	int temp;	//printf("asd\n");
	if(x==y)
	return 0;
	int v = 0;
	
	int *xm,*ym;
	//xm = malloc(4*2);
	//ym = malloc(4*2);
	
	if(x>y)
	{
	xm = point(x);
	ym = point(y);
	}
	
	else
	{
	ym = point(x);
	xm = point(y);
	temp = x;
	x = y;
	y = temp; 
	//printf("%d %d\n",x,y);
	}
	//printf("asd\n");
	if(xm[0] != ym[0])
	{
		v = val(x - xm[1], y) + xm[1];
	}
	if(xm[0] == ym[0])
	{
	  	v = val(x-xm[1], y-ym[1]);
	}
	free(xm);
	free(ym);
	return v;
}
	
int main()
{
	int T;
	int i;
	scanf("%d",&T);
	/*int *x = malloc(sizeof(int)*T);
	int *y = malloc(sizeof(int)*T);
	*/
	int x,y;
	
	for(i=0; i<T; i++)
	{
		scanf("%d %d",&x,&y);
		
		//printf("asd\n");
		x = val(x,y);
		printf("%d\n", x);
		
		//printf(" i is %d\n",i);
		
	}	
	return 0;
}
