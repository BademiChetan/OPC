
/*
********QUESTION DESCRIPTION*************
 
 
* @author (codeKNIGHT) 
 */
//import java.util.*;
import java.math.*;
import java.io.*;
class Main
{
    public static void main(String args[])throws IOException
    {
        //Scanner in=new Scanner(System.in);
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        //FileReader f=new FileReader("C:\\users\\Lokesh\\Desktop\\input.txt");
            //Scanner in=new Scanner(f);
        int t=Integer.parseInt(in.readLine());
        int i,n,k;
        BigInteger b,four;
        four=BigInteger.valueOf(4);
        String s,a[]=new String[2];
        for(i=0;i<t;i++)
        {
            s=in.readLine();
            a=s.split(" ");
            n=Integer.parseInt(a[0]);
            k=Integer.parseInt(a[1]);
           
            //b=two.pow(();
             b=four.pow(n);
             b=b.mod(BigInteger.valueOf(k));
            out.println(b);
        }
        

        out.flush();
    } 
}
