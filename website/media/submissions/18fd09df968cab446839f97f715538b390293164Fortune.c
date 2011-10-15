#include <stdio.h>
#include <math.h>
int main()
{

	double j,n,new2,new3, nf, kf,res;
	scanf("%d", &j);
	
	
	for(;j>0; j--)
	{
		scanf("%d", &n);
		scanf("%f", &kf);
	  	res=pow(2,2*n);
   	/*printf("%f\n",res);
   	new2=res/kf;
   	while(new2!=0)
   	{new3=new2;
   	new2=lrintf(new2/kf);}*/
   	new2=drem(res,kf);
   	printf("%d",new2);
	}
}