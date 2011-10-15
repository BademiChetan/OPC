import java.io.*;
import java.math.BigInteger;
import java.util.*;
class Main{
    int[][]dp;
    void solve()throws Exception
    {
        int T=nextInt();
        for(int test=1;test<=T;test++)
        {
            int n=nextInt();
            int k=nextInt();
            if(k==1)
            {
                System.out.println(0);
                continue;

            }
            int phi=1;
            int t=k;
            for(int i=2;i*i<=t;i++)
                if(t%i==0)
                {
                    int cnt=0;
                    while(t%i==0)
                    {
                        cnt++;
                        if(cnt>1)
                            phi*=i;
                        t/=i;
                    }
                    phi*=i-1;
                }
            if(t>1)
                phi*=t-1;
            BigInteger r=BigInteger.valueOf(2).modPow(BigInteger.valueOf(n),BigInteger.valueOf(phi));
            BigInteger res=BigInteger.valueOf(2).modPow(r,BigInteger.valueOf(k));
            System.out.println(res);
        }
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