
#include<stdio.h>
int main()
{
		long t,x,y,qx,qy,k,l,rx,ry;
		long arr[8][8]={0,1,2,3,4,5,6,7,
							1,0,3,2,5,4,7,6,
							2,3,0,1,6,7,4,5,
							3,2,1,0,7,6,5,4,
							4,5,6,7,0,1,2,3,
							5,4,7,6,1,0,3,2,
							6,7,4,5,2,3,0,1,
							7,6,5,4,3,2,1,0};
		scanf("%ld",&t);
		while(t--)
		{
			scanf("%ld %ld",&x,&y);
			qx=x/8;
			qy=y/8;
			rx=x%8;
			ry=y%8;
			if(qx==0||qy==0)
			l=qx+qy;
			else
			l=qx*qy;
			k=8*l+arr[rx][ry];

			printf("%ld\n",k);
		}
		return 0;
}