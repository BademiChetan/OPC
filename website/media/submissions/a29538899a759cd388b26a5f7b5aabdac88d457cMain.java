
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
        int i,n,s=0,j;
        //String s;
        for(i=0;i<t;i++)
        {
            n=in.nextInt();
            s=0;
            for(j=0;j<n;j++)
            s=s+in.nextInt();
            
            s-=n*(n-1)/2;
            if(s%2==0)
            out.println("LOSE");
            else
            out.println("WIN");
        }

        out.flush();
    } 
}
