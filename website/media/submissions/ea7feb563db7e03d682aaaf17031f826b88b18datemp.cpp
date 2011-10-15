#include<stdio.h>
#include<malloc.h>
int main(){
  int *arr = (int *)malloc(sizeof(int) * 1000000000);
  if(arr == NULL)
    printf(" Out of Memory");
  return 0;
}
