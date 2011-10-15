#include<stdio.h>
#include<stdlib.h>

void quicksort(int arr[],int par[], int low, int high);


int main()
{
	int T,N=0,W=0;
	int* we,*va,*fa,*ra;
	int i,sum=0,j;
	int co = 0;
	
	scanf("%d",&T);

	for( i = 0;i< T;i++)
{
    
	scanf("%d%d",&N,&W);
	 


	if(N!=0)
	{
	
	
	we = (int*)malloc(sizeof(int)*(N));
	fa = (int*)malloc(sizeof(int)*(N));
	va = (int*)malloc(sizeof(int)*(N));
	ra = (int*)malloc(sizeof(int)*(N));}
	
	else
	{
	    printf("%d",0);
	    return 0;
	}

for(j =0;j<N;j++)
{
	scanf("%d%d%d",&we[j],&va[j],&fa[j]);
	ra[j]=va[j]/we[j];	
}
quicksort(ra,fa,0,N-1);
while(W>0)
{
	if(W>fa[co]*we[co])
{
	sum =sum+ fa[co]*we[co];
	W=W-sum;
	co++;	
}
	else
	sum = sum+(W/we[co])*we[co];
co++;
}
printf("%d\n",sum);
}}

void quicksort(int arr[],int par[], int low, int high) {
 int i = low;
 int j = high;
 int y = 0;
 int pa =0;
 /* compare value */
 int z = arr[(low + high) / 2];

 /* partition */
 do {
  /* find member above ... */
  while(arr[i] < z) i++;

  /* find element below ... */
  while(arr[j] > z) j--;

  if(i <= j) {
   /* swap two elements */
   y = arr[i];
   pa = par[i];
   arr[i] = arr[j];
   par[i] = par[j]; 
   arr[j] = y;
   par[j] = pa;
   i++; 
   j--;
  }
 } while(i <= j);

 /* recurse */
 if(low < j) 
  quicksort(arr,par, low, j);

 if(i < high) 
  quicksort(arr,par, i, high); 
}


