import java.io.*;
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
    //HashMap<Integer,Integer>set;
    int[]values;
    int[]cost;
    int res=-1;
    int ind=0;
    void solve()throws Exception
    {
        int T=nextInt();
        for(int test=1;test<=T;test++)
        {
            int n=nextInt();
            Budget=nextInt();
            l=new Item[n/2];
            int len=1;
            for(int i=0;i<l.length;i++)
            {
                l[i]=new Item();
                len*=l[i].F+1;
            }
            r=new Item[n-n/2];
            for(int i=0;i<r.length;i++)
            {
                r[i]=new Item();
            }
            //set=new HashMap<Integer,Integer>();
            values=new int[len];
            cost=new int[values.length];
            ind=0;
            rec(0,0,0);
            Integer[]order=new Integer[cost.length];
            for(int i=0;i<order.length;i++)
                order[i]=i;
            Arrays.sort(order,new Comparator<Integer>(){
                public int compare(Integer a,Integer b)
                {
                    return cost[a]-cost[b];
                }
            });
            int[]C=new int[cost.length];
            int[]V=new int[cost.length];
            for(int i=0;i<C.length;i++)
            {
                C[i]=cost[order[i]];
                V[i]=values[order[i]];
            }
            cost = C;
            values=V;
            int curMax=0;
            for(int i=0;i<cost.length;i++)
            {
                curMax = Math.max(curMax,values[i]);
                values[i]=curMax;
            }
            rec2(0,0,0);
            System.out.println(res);
        }
    }

    private void rec(int at, int value, int sumCost) {
        if(sumCost>Budget)
            return;
        if(at==l.length)
        {
            cost[ind]=sumCost;
            values[ind++]=value;
            return;
        }
        for(int x=0;x<=l[at].F;x++)
        {
           rec(at+1,value+l[at].value*x,sumCost+l[at].cost*x);
        }
    }
    private void rec2(int at, int value, int sumCost) {
        if(sumCost>Budget)
            return;

        if(at==r.length)
        {
            int remains=Budget-sumCost;
        int low=0;
        int high=values.length;
        while(high-low>1)
        {
            int mid=(low+high)>>1;
            if(cost[mid]<=remains)
                low=mid;
            else
                high=mid;
        }
        res=Math.max(res,value+values[low]);
            return;
        }

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