
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
        int i,x,y;
        //String s;
        for(i=0;i<t;i++)
        {
            x=in.nextInt();
            y=in.nextInt();
            out.println(x^y);
        }

        out.flush();
    } 
}
