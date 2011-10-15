
/*
********QUESTION DESCRIPTION*************
 
 
* @author (codeKNIGHT) 
 */
import java.util.*;
//import java.math.*;
import java.io.*;
class Main
{
    public static void main(String args[])//throws IOException
    {
        Scanner in=new Scanner(System.in);
        PrintWriter out=new PrintWriter(System.out);
        //FileReader f=new FileReader("C:\\users\\Lokesh\\Desktop\\input.txt");
            //Scanner in=new Scanner(f);
        int t=in.nextInt();
        int i,n,w,p,j,k,cost,value,f;
       // String s;
        for(i=0;i<t;i++)
        {
            n=in.nextInt();
            w=in.nextInt();
            p=1;
            int weight[]=new int[100001];
            int profit[]=new int[100001];
            for(j=0;j<n;j++)
            {
                cost=in.nextInt();
                value=in.nextInt();
                f=in.nextInt();
                for(k=0;k<f;k++)
                {
                    weight[p]=cost;
                    profit[p]=value;
                    p++;
                }
            }
            //System.out.println(p);
            int opt[][]=new int [p+1][w+1];
            int opt1,opt2;
            for(j=1;j<=p;j++)
            {
                for(k=1;k<=w;k++)
                {
                    opt1=opt[j-1][k];
                    opt2=Integer.MIN_VALUE;
                    if(weight[j]<=k)
                    opt2=profit[j]+opt[j-1][k-weight[j]];
                    opt[j][k]=Math.max(opt1,opt2);
                }
            }
            out.println(opt[p][w]);
        }
                

        out.flush();
    } 
}
