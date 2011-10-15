#include<stdio.h>
#include<stdlib.h>

int sqaure_next_element(int square[1000][1000], int a, int b)
{
    int i, j;
    int allelems[a+b];
    for(i=0; i<b; i++)
        allelems[i] = square[a][i];
    for(j=0; j<a; j++)
        allelems[i+j] = square[j][b];
    
    for(i=0; i<a+b; i++)
    {
        if(search(allelems, i, a+b) == 0)
            continue;
        else
            return i;
    }
    return i;
}

merge(int a[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i=low;
    j=mid+1;
    k=low;
    while((i<=mid)&&(j<=high))
    {
    if(a[i]<a[j])
    {
    c[k]=a[i];
    k++;
    i++;
    }
    else
    {
    c[k]=a[j];
    k++;
    j++;
    }
    }
    while(i<=mid)
    {
    c[k]=a[i];
    k++;
    i++;
    }
    while(j<=high)
    {
    c[k]=a[j];
    k++;
    j++;
    }
    for(i=low;i<k;i++)
    {
    a[i]=c[i];
    }
}

int mergesort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,high,mid);
    }
}

int binary_search(int a[], int low, int high, int target) {
    if (high < low)
        return -1;
    int middle = (low + high)/2;
    if (target < a[middle])
        return binary_search(a, low, middle-1, target);
    else if (target > a[middle])
        return binary_search(a, middle+1, high, target);
    else if (target == a[middle])
        return middle;
}

int search(int allelems[], int a, int n)
{
/*    int i;
    for(i=0; i<n; i++)
        if(a == allelems[i])
            return 0;
    return 1;
*/
    mergesort(allelems, 0, n-1);
    if(binary_search(allelems, 0, n-1, a) == -1)
        return 1;
    else
        return 0;
}

int main()
{
    int T;
    int X, Y;
    int i;
    int j, k;
    int square[1000][1000];
//  int square[N][N];
//  int big, small;
    
    scanf("%d", &T);
    int temp[T];
    for(i=0; i<T; i++)
    {
        scanf("%d %d", &X, &Y);
/*        if(X>Y)
            big = X; small = Y;
        else
            big = Y; small = X; */
        for(j=0; j<=X; j++)
            for(k=0; k<=Y; k++)
                square[j][k] = sqaure_next_element(square, j, k);
        
//      printf("%d\n", square[X][Y]);
        temp[i] = square[X][Y];
    }
    for(i=0; i<T; i++)
        printf("%d\n", temp[i]);

    return 0;
}
