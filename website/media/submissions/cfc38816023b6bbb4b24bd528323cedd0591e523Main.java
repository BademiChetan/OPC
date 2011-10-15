import java.io.*;
import java.math.BigInteger;
import java.util.*;
class Main{

    class Item
    {
        public int cost,value,F;
        public Item()throws Exception
        {
            cost= nextInt();
            value=nextInt();
            F=nextInt();
        }


    }

    int Budget;
    Item[]l;
    Item[]r;
    HashMap<Integer,Integer>set;
    int[]values;
    int[]cost;
    int res=-1;
    void solve()throws Exception
    {
        int T=nextInt();
        for(int test=1;test<=T;test++)
        {
            int n=nextInt();
            Budget=nextInt();
            l=new Item[n/2];
            for(int i=0;i<l.length;i++)
            {
                l[i]=new Item();
            }
            r=new Item[n-n/2];
            for(int i=0;i<r.length;i++)
            {
                r[i]=new Item();
            }
            set=new HashMap<Integer,Integer>();
            rec(0,0,0);
            values=new int[set.size()];
            cost=new int[set.size()];
            int at=0;
            for(int x : set.keySet())
            {
                cost[at++]=x;
            }
            Arrays.sort(cost);
            int curMax=0;
            for(int i=0;i<cost.length;i++)
            {
                curMax = Math.max(curMax,set.get(cost[i]));
                values[i]=curMax;
            }
            rec2(0,0,0);
            System.out.println(res);
        }
    }

    private void rec(int at, int value, int sumCost) {
        if(sumCost>Budget)
            return;
        if(!set.containsKey(sumCost) || set.get(sumCost)<value)
            set.put(sumCost,value);
        if(at>=l.length)
            return;
        for(int x=0;x<=l[at].F;x++)
        {
           rec(at+1,value+l[at].value*x,sumCost+l[at].cost*x);
        }
    }
    private void rec2(int at, int value, int sumCost) {
        if(sumCost>Budget)
            return;
        int remains=Budget-sumCost;
        int i=Arrays.binarySearch(cost,remains);
        if(i<0)
        {
            i++;
            i=-i;
            i--;
        }
        res=Math.max(res,value+values[i]);
        if(at>=r.length)
            return;
        for(int x=0;x<=r[at].F;x++)
        {
           rec2(at+1,value+r[at].value*x,sumCost+r[at].cost*x);
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