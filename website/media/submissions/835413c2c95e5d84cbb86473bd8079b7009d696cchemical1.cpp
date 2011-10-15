#include<stdio.h>
#include<iostream>
using namespace std;

int main(){

int testcase;
int n;
long long int item[10][3],bud;
int i,temp;
int j,k;
int val[10];
bool flag;

cin>>testcase;
for(i=0;i<testcase;i++){
	cin>>n>>bud;
	for(j=0;j<n;j++){
		cin>>item[j][0]>>item[j][1]>>item[j][2];
	}
	for(k=0;k< n-1;k++){
		flag=true;
		for(j=0; j < n-1-k; j++){
			if( (item[j][1]/item[j][0]) < (item[j+1][1])/item[j][0]){
				temp = item[j][0];
				item[j][0] = item[j+1][0];
				item[j+1][0] = temp;		
			
				temp = item[j][1];
				item[j][1] = item[j+1][1];
				item[j+1][1] = temp;
				
				temp = item[j][2];
				item[j][2] = item[j+1][2];
				item[j+1][2] = temp;
				
				flag = false;
			} 
			
			else if( (item[j][1]/item[j][0]) == (item[j+1][1]/item[j][0]) ){
				if(item[j][1] > item[j+1][1]){
					
					temp = item[j][0];
					item[j][0] = item[j+1][0];
					item[j+1][0] = temp;		
			
					temp = item[j][1];
					item[j][1] = item[j+1][1];
					item[j+1][1] = temp;
				
					temp = item[j][2];
					item[j][2] = item[j+1][2];
					item[j+1][2] = temp;
					
					flag = false;
				
				}
				
			
					
			}
			
			
			
		} 
		
		if(flag) break;
	
	} /* end of sort*/
		
	val[i] = 0;
	for(j=0;(j<n && bud !=0) ;j++){
		if((item[j][0] * item[j][2])<bud){
			bud-=item[j][0] * item[j][2];
			val[i]+=item[j][1]*item[j][2];
		}
		else{
			temp = bud/item[j][0];
			bud = bud % item[j][0];
			val[i]+=temp*item[j][1];
		}
		
	}		
	
	

}

for(i=0;i<testcase;i++){
	cout<<val[i]<<"\n";
}


	
return 0;
	
}
