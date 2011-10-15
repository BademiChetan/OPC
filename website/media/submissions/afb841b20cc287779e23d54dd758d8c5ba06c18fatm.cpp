#include<stdio.h>
#include<conio.h>

int main(){
    int w;
    float bal;
    scanf("%d %f", &w, &bal);
    
    if(w>(bal-0.5)||(w%5!=0))
      printf("%.2f", bal);
    else
      printf("%.2f", (bal-0.5-w));
    getch();
    return 0;
}
