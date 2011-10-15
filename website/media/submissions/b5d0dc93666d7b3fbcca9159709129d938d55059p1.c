#include <stdio.h>
#include <math.h>

int array[4][4]  = { {0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,0,1} };

int func(int x, int y, int count){
	if(x<4 && y<4)
		return count + array[x][y];
	int a =  x;
	if(y>x)
		a = y;
	int alpha = ceil(log(a)/log(4));
	int bx = x/(pow(4,alpha-1));
	int by = y/(pow(4,alpha-1));
	int b = array[bx][by];
	int x1 = x%((int)pow(4,alpha-1));
	int y1 = y%((int)pow(4,alpha-1));
	return func(x1,y1,count+((int)pow(4,alpha-1)*b));
	
}

int main(){
	
	
	int cases;
	scanf("%d",&cases);
	int t1 = 0;
	int result[cases];
	while(t1<cases){
		int c1,c2;
		scanf("%d %d",&c1,&c2);
		result[t1] = func(c1,c2,0);//calculate
		t1++;
	}
	t1 = 0;
	while(t1<cases){
		printf("%d\n",result[t1]);
		t1++;
	}
	return 0;
}
