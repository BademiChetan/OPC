
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
        int i,n,k,p,x,y,z;
        int ar[]={1,2,4,8,16,32,64,128,256,512,1024,
                  2048,4096,8192,16382,32768,65536,131072,262144,524288,1048576,
                  2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
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
            while(k>ar[p])
            p++;
            if(n>p/2)
            {x=ar[p]%k;
            
            y=(2*n)%p;
            z=(int)Math.pow(2,y)*x;
            z=z%k;
             out.println(z);
        }
        else
        out.println(ar[2*n]%k);
           
        }
    }

        out.flush();
    } 
}
