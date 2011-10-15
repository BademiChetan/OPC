#include <stdio.h>
#include <math.h>
int main()
{
	//float fort,k,new1;
	int j,n,new2,fort1,k1;
	float nf, kf;
	float res;
	//scanf("%d", &j);
	/*for(;j>0;j--)
	{
			scanf("%d",&n);
			scanf("%lf",&k);
			fort=pow(2,n);
			if ((fort<32768.00) && (k<32768.00))
				{fort1=(int) fort;
				k1=(int) k;
					new2=fort1%k1;
				printf("%d",new2); continue;}
				new1=fort/k;
				printf("%f",new1);
			//while((new1=fort/k)>k);
			printf("%d",new1);
	}
	*/
	
	scanf("%d", &j);
	
	
	for(;j>0; j--)
	{
		scanf("%d", &n);
		scanf("%f", &kf);
		
		
		
   	res=pow(2,2*n);
   	printf("%f\n",res);
   	new2=res/kf;
   	if (new2>kf)
   	new2=new2/kf;
   	new2=new2+1;
   	printf("%d",new2);
	}
}