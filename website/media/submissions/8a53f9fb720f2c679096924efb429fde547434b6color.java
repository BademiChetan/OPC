import java.io.*;
import java.util.*;

class color
 {


    public static void main(String s[])  throws Exception
	{
	  int sr=0;
	 int sc=0;
	 int st =0, r,c;
	try
	{  
	BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
	
    	
	System.out.println("Enter the N : ");
	int n = Integer.parseInt(br.readLine());
	  sr =sc=n;
	
	int clr[][] = new int[sr][sc];

	for(int i=0;i<sr;i++)
	for(int j=0;j<sc;j++)
	{
	    if(j == (sc-1))
	     { 
	        clr[i][j]= (sc-1-i);
	        st= sc-1-i;
	      }
	   else
       	    {
	      if( st == sc)st=0;
	      clr[i][j]=st;
	      st +=1;
	     }
	}
	  

	for(int i=0;i<sr;i++)
	{
	System.out.println("\n");
	for(int j=0;j<sc;j++)
	System.out.print("\t"+clr[i][j]);
	}

	System.out.println("\n Enter the no of test case : ");
	 n = Integer.parseInt(br.readLine());
	for(int i=0 ;i< n;i++)
	{
	 System.out.println("Enter the \t "+ i+"  test case : ");
	 r =  Integer.parseInt(br.readLine());
                  c  = Integer.parseInt(br.readLine());
	 System.out.println("The color is :  "+clr[r][c]);

	}

 	}
	catch(Exception e)
	{}

	}	
}                          			