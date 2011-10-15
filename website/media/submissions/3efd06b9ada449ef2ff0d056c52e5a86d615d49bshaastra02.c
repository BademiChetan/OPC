#include<stdio.h>
#include<string.h>
int mem[101][101][2];

int solve(int even, int odd,int t)
{
   int res;
   if(even<0 || odd<0 || (even==0 && odd==0))return t;
   if(mem[even][odd][t]>-1)return mem[even][odd][t];

   if(t%2!=0)
   {
      if(even>=2)
      res = solve(even-2,odd+1,1-t);
		else res=0;
      if(!(even==0 && odd<=1))
      res|=solve(even,odd-1,1-t);
   }
   else
   {
      if(!(even<=1 && odd==0))
      res = solve(even-1,odd,1-t);
		else res=1;
      if(odd>=2)
      res&=solve(even+1,odd-2,1-t);
   }

   mem[even][odd][t]=res;
   return res;

}

int main()
{
   int test,even,odd,n,num,i;
   scanf("%d",&test);
   memset(mem,-1,sizeof(mem));
   mem[0][1][0]=1,mem[0][1][1]=1,mem[1][0][0]=0,mem[1][0][1]=0;
   while(test--)
   {
      even=0,odd=0;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
         scanf("%d",&num);
         if(num%2==0)even++;
         else odd++;
      }
      if(solve(even,odd,1))printf("WIN\n");
      else printf("LOSE\n");
   }
   return 0;
}
