

import java.util.*;



class Main {

    static class Ob
    {
        int item,budget;
        public Ob(int it,int bud)
        {
            item=it;
            budget=bud;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final Ob other = (Ob) obj;
            if (this.item != other.item) {
                return false;
            }
            if (this.budget != other.budget) {
                return false;
            }
            return true;
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 71 * hash + this.item;
            hash = 71 * hash + this.budget;
            return hash;
        }
    }
    /**
     * @param args the command line arguments
     */
    static int n;
    static int arr[][];
    static HashMap<Ob,Integer> map;
    public static void main(String[] args)
    {
        Scanner pd=new Scanner(System.in);
        int t=pd.nextInt();
        while(t-->0)
        {

            n=pd.nextInt();
            int bud=pd.nextInt();
            map=new HashMap<Ob,Integer>();
            arr=new int[n][3];
            for(int i=0;i<n;i++)for(int j=0;j<3;j++)arr[i][j]=pd.nextInt();
            System.out.println(find(0,bud));
        }

    }
    public static int find(int item,int budget)
    {
        if(item==n)
            return 0;
        if(budget<0)
            return -1000000000;
        if(budget==0)return 0;
        Ob tmp=new Ob(item,budget);
        if(map.containsKey(tmp))return map.get(tmp);
        int max=0;
        for(int i=0;i<=arr[item][2];i++)
        {
            max=Math.max(max,i*arr[item][1]+find(item+1,budget-i*arr[item][0]));
        }
        map.put(tmp, max);
        return max;
    }
}


