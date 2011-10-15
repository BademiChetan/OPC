/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author home
 */
import java.io.*;
import java.math.BigInteger;
public class cow {
public static void main(String args[])throws Exception
{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    int t=Integer.parseInt(br.readLine());
    int i,n,k;
    String r;
    String []temp;
    BigInteger b=BigInteger.valueOf(2);
   BigInteger m;
    for(i=0;i<t;i++)
    {
         b=BigInteger.valueOf(2);
         r=br.readLine();
         temp=r.split(" ");
         n=Integer.parseInt(temp[0]);
         k=Integer.parseInt(temp[1]);
           m=BigInteger.valueOf(k);
         b=b.pow(n);

         b=b.mod(m);
         System.out.println(b);


    }
    }
}

