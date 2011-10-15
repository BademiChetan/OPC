
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
        int i,n,q,start,l,j,c;
        String s,x,y;
        for(i=0;i<t;i++)
        {
            n=in.nextInt();
            s=in.next();
            q=in.nextInt();
            for(i=0;i<q;i++)
            {
                start=in.nextInt();
                l=in.nextInt();
                x=s.substring(start,start+l);
                c=0;
                for(j=0;j<=n-l;j++)
                {
                    y=s.substring(j,j+l);
                    if(y.equals(x))
                    c++;
                }
                out.println(c);
            }
        }

        out.flush();
    } 
}
