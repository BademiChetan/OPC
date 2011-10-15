/**
 * @(#)main.java
 *
 *
 * @author 
 * @version 1.00 2011/9/25
 */
import  java.io.*;
import java.util.*;

 class Main {
	String str;
    public Main() {
    }
    public static void main(String ar[])
    {
    	try{
    	
    	Main m=new Main();
		int p, start[], qLength[];
		String k=null;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in ));
		String t=null;
		t=br.readLine();
		int i,j=0,n=Integer.parseInt(t);
		//String st;
		//StringTokenizer str;
		for(i=0;i<n;i++)
		{
			br.readLine();//size of string
			m.str=br.readLine();
			t=br.readLine();
			p=Integer.parseInt(t);//No of queries
			//q=new String[p];
			start=new int[p];
			qLength=new int[p];
			for(j=0;j<p;j++)
			{
			
			 t=br.readLine();
			 StringTokenizer s=new StringTokenizer(t);
			while(s.hasMoreTokens())
			{
            	//System.out.println("first token");
				if(s.hasMoreTokens())
					k=s.nextToken();
				start[j]=Integer.parseInt(k);
				if(s.hasMoreTokens())
					k=s.nextToken();
				qLength[j]=Integer.parseInt(k);
				//m.find(start[j], qLength[j]);
			} 
		}    
			//	System.out.println("start");
			for(i=0;i<p;i++)
			{//	System.out.print("query");
				m.find(start[i], qLength[i]);
			
			}       
			//if()
	//			System.out.println(m.isWin());
		}
	
    	}catch(Exception els)
    	{
    		els.printStackTrace();
    	}
    }
    void find(int start, int length)
    {
    	int c=0,j=0,i=str.length();
    //	BufferedReader br=new BufferedReader(new InputStreamReader(System.in ));
		
	//			System.out.println("in find");
    //start--;
    	while(i>=0){
    		
    		
				j=str.lastIndexOf(str.substring(start,start+length), i);
    		i=j-1;
    		if(j>=0)
    			c++;
 //   		System.out.println("substring:"+str.substring(start,start+length)+"c="+c+"i="+i+"j="+j);
    		
 	//		try{   
 	//		br.readLine();
 	//		}catch(Exception e){}
    	}System.out.println(c);
    	
    
    }
    
    
}