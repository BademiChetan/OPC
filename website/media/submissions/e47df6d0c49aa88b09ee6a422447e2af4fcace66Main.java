
/*
********QUESTION DESCRIPTION*************
 
 
* @author (codeKNIGHT) 
 */
import java.util.*;
import java.math.*;
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
        int i,n,k;
        BigInteger b,four;
        four=BigInteger.valueOf(4);
        for(i=0;i<t;i++)
        {
            n=in.nextInt();
            k=in.nextInt();
            b=four.pow(n);
            //b=two.pow(();
            if(k==1)
            out.println(0);
            else
            out.println(b);
        }

        out.flush();
    } 
}
