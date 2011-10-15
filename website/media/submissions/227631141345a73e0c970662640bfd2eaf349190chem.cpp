#include<iostream>
using namespace std;

long int t;
double tempo;

long int x,y;

int main(){
long int i;
long int n;
double budget,left;


cin>>t;

for(;t>0;--t){

double tvalue=0;

cin>>n;
cin>>budget;
left=budget;
double cost[n],value[n],avail[n];
long int take[n];
double eff[n],temp;

for(i=0;i<n;++i){
//scanf("%lf %lf %lf",&cost[i],&value[i],&avail[i]);
cin>>cost[i];
cin>>value[i];
cin>>avail[i];

if(cost[i]==0){
eff[i]=10000000;
}
}

 
for( x=0; x<n; x++)
	{
		for( y=0; y<n-1; y++)
		{
       if((eff[y]<eff[y+1])||((eff[y]=eff[y+1])&&(cost[y]<cost[y+1]))){
	             temp = eff[y+1];
				eff[y+1] = eff[y];
				eff[y] = temp;			
			 //  //sort cost aac eff
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

    if((take[i]>=avail[i])||(cost[i]==0)){
        take[i]=avail[i];

            }
            

left=left-(take[i]*cost[i]);
tvalue+=(take[i]*value[i]);


}
					
cout<<tvalue<<"\n";

}

return 0;
}


