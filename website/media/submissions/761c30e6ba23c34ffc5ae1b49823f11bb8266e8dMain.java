
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
        int i,n,q,start,l,j,c;
        String s,x,y,a[]=new String[2];
        for(i=0;i<t;i++)
        {
            n=Integer.parseInt(in.readLine());
            s=in.readLine();
            q=Integer.parseInt(in.readLine());
            for(i=0;i<q;i++)
            {
                x=in.readLine();
                a=x.split(" ");
                start=Integer.parseInt(a[0]);
                l=Integer.parseInt(a[1]);
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
