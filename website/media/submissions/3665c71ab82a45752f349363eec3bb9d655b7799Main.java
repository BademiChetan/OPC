

import java.util.*;



class Main {

    /**
     * @param args the command line arguments
     */
    static int n;
    static int arr[][];
    static long[][] dp;
    public static void main(String[] args)
    {
        Scanner pd=new Scanner(System.in);
        int t=pd.nextInt();
        while(t-->0)
        {

            n=pd.nextInt();
            int bud=pd.nextInt();
            dp=new long[n][bud+1];
            arr=new int[n][3];
            for(int i=0;i<n;i++)for(int j=0;j<3;j++)arr[i][j]=pd.nextInt();
            System.out.println(find(0,bud));
        }

    }
    public static long find(int item,int budget)
    {
        if(item==n)
            return 0;
        if(budget<0)
            return -1000000000;
        if(dp[item][budget]>0)return dp[item][budget]-1;
        long max=-100000000;
        for(int i=0;i<=arr[item][2];i++)
        {
            max=Math.max(max,i*arr[item][1]+find(item+1,budget-i*arr[item][0]));
        }
        dp[item][budget]=max+1;
        return max;
    }
}

