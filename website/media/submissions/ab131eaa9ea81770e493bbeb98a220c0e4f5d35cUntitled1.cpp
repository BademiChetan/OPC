
 #include <stdio.h>
 #include<conio.h>
 int binarysearch(int a[],int n,int low,int high)
 { int mid;
 if (low > high)
 return -1;
 mid = (low + high)/2;
 if(n == a[mid])
 { printf("The element is at position %d\n",mid+1);
 getch();
 return 0;} if(n < a[mid])
 { high = mid - 1;
 binarysearch(a,n,low,high);
 }
 if(n > a[mid])
 { low = mid + 1;
 binarysearch(a,n,low,high);
 }
 }
 int main()
 { int a[50];
 int n,no,x,result;
 printf("Enter the number of terms : ");
 scanf("%d",&no);
 printf("Enter the elements :\n");
 for(x=0;x<no;x++)
 scanf("%d",&a[x]);
 printf("Enter the number to be searched : ");
 scanf("%d",&n);
 result = binarysearch(a,n,0,no-1);
 if(result == -1)
 printf("Element not found");

 return 0;
}
