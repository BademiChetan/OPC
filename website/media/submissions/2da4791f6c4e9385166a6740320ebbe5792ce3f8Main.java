
/*
********QUESTION DESCRIPTION*************
 
 
* @author (codeKNIGHT) 
 */
//import java.util.*;
//import java.math.*;
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
        int i,n,k,p,x,y,z,q;
        
        String s,a[]=new String[2];
        for(i=0;i<t;i++)
        {
            s=in.readLine();
            a=s.split(" ");
            n=Integer.parseInt(a[0]);
            k=Integer.parseInt(a[1]);
            p=0;
            if(k==1)
           out.println(0);
           else
           {
               if(2*n<=30)
               out.println((int)Math.pow(2,2*n)%k);
               else
               {
            p=Integer.toBinaryString(k).length();
            q=(int)Math.pow(2,p);
            
            x=q%k;
            
            y=(2*n)%p;
            z=(int)Math.pow(2,y)*x;
            z=z%k;
             out.println(z);
        }
       
           
        }
    }

        out.flush();
    } 
}
