#include <stdio.h>
#include <stdlib.h>
 
int arr[101];
int banyak,z;
int turn = 1;
 

int main()
{
 int t;
 scanf("%d",&t);
 for(int x=0;x<t;x++)
 {
   scanf("%d",&z); 
   int turn=1;
   banyak =z;
   for(int y=1;y<=z;y++)
   {
     scanf("%d",&arr[y]);
   }  
   int hasil = arr[1] + arr[2]-turn;
   int j=2;
   arr[1] = hasil;
   while(banyak >0){
    arr[j] = arr[j+1];         
    banyak--; 
    j++;        
   }
  turn++;  
   if(arr[1]%2==0)
     printf("LOSE\n");
   else
     printf("WIN\n");
 
   
 }
}
