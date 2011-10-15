#include<stdio.h>
#include<malloc.h>
#include<assert.h>
int main(){
  int *arr = (int *)malloc(sizeof(int) * 1000000000);
  assert(arr != NULL);
  if(arr == NULL)
    printf(" Out of Memory");
  return 0;
}
