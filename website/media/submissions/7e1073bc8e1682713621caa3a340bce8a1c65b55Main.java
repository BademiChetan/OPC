import java.io.*;
import java.util.*;
class Main
{
    static long N,K;
    public static long mod(long k){
        long ans=1;
        long pow=2;        
        while(k!=0){
            if(k%2!=0) ans=(ans*pow)%K;
            pow=(pow*pow)%K;
            k/=2;
        }
        return ans%K;
    }
    public static void main(String args[])throws Exception
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(in.readLine());
        PrintWriter out=new PrintWriter(System.out);
        StringTokenizer ss;
        for(int i=1;i<=t;i++)
        {
            ss=new StringTokenizer(in.readLine());
            N=Long.parseLong(ss.nextToken());
            K=Long.parseLong(ss.nextToken());                   
            out.println(mod(mod(N)));
        }
        out.flush();
    }
}