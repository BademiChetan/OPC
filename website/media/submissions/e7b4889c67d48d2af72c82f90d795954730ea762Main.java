import java.io.*;
import java.util.*;
class Main{


    void solve()throws Exception
    {
        int T=nextInt();
        for(int test=1;test<=T;test++)
        {
            int x=nextInt();
            int y=nextInt();
            int res=rec(x,y);
            System.out.println(res);
        }
    }

    private int rec(int x, int y) {
        if(x==0)
            return y;
        x--;
        int k=0;
        while(x>(1<<k)-1)
        {
            x-=1<<k;
            k++;
        }
        int res=(y/(1<<(k+1)))*(1<<(k+1));
        if(y%(1<<(k+1))<1<<k)
            res+=1<<k;
        res+=rec(x,y%(1<<k));
        return res;
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