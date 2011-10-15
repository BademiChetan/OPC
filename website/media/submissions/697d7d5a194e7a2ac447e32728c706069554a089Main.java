import java.io.*;
import java.util.*;
public class Main{
    int[][]dp;
    void solve()throws Exception
    {
        int T=nextInt();
        for(int test=1;test<=T;test++)
        {
            int n=nextInt();
            int odds=0;
            int even=0;
            for(int i=0;i<n;i++)
                if(nextInt()%2==0)
                    even++;
                else
                    odds++;
            dp=new int[n+1][n+1];

            for(int i=0;i<=n;i++)
                Arrays.fill(dp[i],-1);
            int res=go(odds,even,1);
            System.out.println(res==1?"WIN":"LOSE");


        }
    }

    private int go(int odds, int even, int t) {
        if(dp[odds][even]!=-1)
            return dp[odds][even];
        if(odds==0 && even==1)
            return dp[odds][even]=2;
        else if(even==0 && odds==1)
            return dp[odds][even]=1;
        int res;
        if(t%2==1)
        {
            res=2;
            if(odds>1)
            {
                if(go(odds-1,even,t+1)==1)
                    res=1;
            }
            if(even>1)
            {
                if(go(odds+1,even-2,t+1)==1)
                    res=1;
            }
            if(odds>0 && even>0)
            {
                if(go(odds-1,even,t+1)==1)
                    res=1;
            }
        }
        else
        {
            res=1;
            if(odds>1)
            {
                if(go(odds-2,even+1,t+1)==2)
                    res=2;
            }
            if(even>1)
            {
                if(go(odds,even-1,t+1)==2)
                    res=2;
            }
            if(odds>0 && even>0)
            {
                if(go(odds,even-1,t+1)==2)
                    res=2;
            }
        }
        return dp[odds][even]=res;

    }


    ////////////
    BufferedReader reader;
    PrintWriter writer;
    StringTokenizer stk;
    void run()throws Exception
    {
        reader=new BufferedReader(new InputStreamReader(System.in));
        stk=null;
        writer=new PrintWriter(System.out);
        solve();
        reader.close();
        writer.close();
    }
    int nextInt()throws Exception
    {
        return Integer.parseInt(nextToken());
    }

    long nextLong()throws Exception
    {
        return Long.parseLong(nextToken());

    }
    double nextDouble()throws Exception
    {
        return Double.parseDouble(nextToken());


    }

    String nextString()throws Exception
    {
        return nextToken();
    }
    String nextLine()throws Exception
    {
        return reader.readLine();
    }
    String nextToken()throws Exception
    {
        if(stk==null || !stk.hasMoreTokens())
        {
            stk=new StringTokenizer(nextLine());
            return nextToken();

        }
        return stk.nextToken();
    }

    public static void main(String[]args) throws Exception
    {
        new Main().run();
    }



}