#include<stdio.h>
int t,tempo;

int x,y;

int main(){
int i;
int n,budget,left;
int tvalue=0;

scanf("%d",&t);
for(;t>0;--t){
scanf("%d %d",&n,&budget);
left=budget;
int cost[n],value[n],avail[n];
int take[n];
float eff[n],temp;

for(i=0;i<n;++i){
scanf("%d %d %d",&cost[i],&value[i],&avail[i]);
eff[i]=value[i]/cost[i];
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
take[i]=left/cost[i];

    if(take[i]>avail[i]){
        take[i]=avail[i];

            }

left=left-(take[i]*cost[i]);
tvalue+=(take[i]*value[i]);

}
						
printf("%d\n",tvalue);

}
return 0;
}


