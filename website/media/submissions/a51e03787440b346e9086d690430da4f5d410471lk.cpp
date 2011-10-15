#include <stdio.h>
#include <stdlib.h>
 
int arr[101];
int banyak;
int turn = 1;
 

int main()
{
int t;
scanf("%d",&t);
 
for(int x=0;x<t;x++)
{
 
        int z;
        scanf("%d",&z);
        turn = 1;
        banyak = z;
        for(int y=0;y<z;y++)
        {
                scanf("%d",&arr[y]);
        }
 
       while(1)
{
        int hasil = arr[0] + arr[1]-turn;;
        arr[0] = hasil;
        if(banyak>0)
        {
                for(int beh=1;beh<banyak;beh++)
                arr[beh] = arr[beh+1];
                banyak--;
        }
        else
                break;
 
        turn++;
}
 
 
if(arr[0]%2==0)
printf("WIN\n");
else
printf("LOSE\n");
 
 
}
 
return 1;
}
 
