# include<stdio.h>
# include<math.h>
int main()
{
	 long long int t,i,n,k,x,y;
	scanf("%lld",&t);
	
        for(i=1;i<=t;i++)
        {
                scanf("%lld %lld",&n,&k);
                //x = pow(2,n);
                //y = pow(2,x) % k;
                if(n>(k+1))
                {
                        printf("1\n");
                }
                else
                {
                        x = pow(2,n);
                        y = pow(2,x);
                        while(y>=k)
                        {
                                y = y /k;
                        }
                                
                        
                
                        printf("%lld \n",y);
                }
        }

}
