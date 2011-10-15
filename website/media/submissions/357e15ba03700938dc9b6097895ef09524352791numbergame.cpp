#include<stdio.h>
//#include<conio.h>
//#include<vector>
//#include<algorithm>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
      
      int N,sum=0;
      int ans,tot;
      //vector <int> numbers;
      scanf("%d",&N);
      int i,temp;
      for(i=0;i<N;i++)
      {
       scanf("%d",&temp);
       sum+=temp;
       //numbers.push_back(temp);
      }
      //printf("%d\n",sum);
      tot=(N)*(N-1);
      tot=tot/2;
      //S      printf("%d\n",n);
     ans=sum-tot;
      //printf("%d",ans);
      if(ans%2==1)
      printf("WIN\n");
      else
      printf("LOSE\n");
    }
  //  getch();
    return 0;
    
}
