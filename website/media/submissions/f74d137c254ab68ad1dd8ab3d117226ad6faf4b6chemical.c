#include<stdio.h>
long int t;
float tempo;

long int x,y;

 main(){
long int i;
long int n;
float budget,left;


scanf("%ld",&t);
for(;t>0;--t){
float tvalue=0;
scanf("%ld %f",&n, &budget);
left=budget;
float cost[n],value[n],avail[n];
long int take[n];
float eff[n],temp;

for(i=0;i<n;++i){
scanf("%f %f %f",&cost[i],&value[i],&avail[i]);
if(cost[i]==0){
eff[i]=1000000000;
}
}

 
for( x=0; x<n; x++)
	{
		for( y=0; y<n-1; y++)
		{
       if(eff[y]<eff[y+1]){
	             temp = eff[y+1];
				eff[y+1] = eff[y];
				eff[y] = temp;			
			   //sort cost aac eff
			   tempo = cost[y+1];
				cost[y+1] = cost[y];
				cost[y] = tempo;
				 
				 tempo = value[y+1];
				value[y+1] = value[y];
				value[y] = tempo;
							
			  	 tempo = avail[y+1];
				avail[y+1] = avail[y];
				avail[y] = tempo;			
			  		
	}
	}
	}		  


			
for(i=0;i<n;++i){
if(cost[i]!=0)
take[i]=left/cost[i];
//printf("%ld     ",take[i]);
    if((take[i]>avail[i])||(cost[i]==0)){
        take[i]=avail[i];

            }
//printf("%ld   \n",take[i]);
left=left-(take[i]*cost[i]);
tvalue+=(take[i]*value[i]);

}
					
printf("%ld\n",(long int)tvalue);

}

}


