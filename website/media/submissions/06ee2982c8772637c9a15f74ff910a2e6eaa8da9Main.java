

import java.io.*;
import java.util.*;

class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer tokenizer=null;
	
	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
	
	void debug(Object...os)
	{
		System.out.println(Arrays.deepToString(os));
	}
	
	int ni() throws IOException
	{
		return Integer.parseInt(ns());
	}
	
	long nl() throws IOException 
	{
		return Long.parseLong(ns());
	}
	
	double nd() throws IOException 
	{
		return Double.parseDouble(ns());
	}
		
	String ns() throws IOException 
	{
		while (tokenizer == null || !tokenizer.hasMoreTokens()) 
			tokenizer = new StringTokenizer(br.readLine());
		return tokenizer.nextToken();
	}
	
	String nline() throws IOException
	{
		tokenizer=null;
		return br.readLine();
	}
		
	

	//Main Code starts Here
	int totalCases;	
	int power[];

	void execute() throws IOException
	{
		totalCases = ni();
		power = new int [21];
		power[0] = 0;
		for(int i = 1;i<21;i++)
		{
			power[i] = (power[i-1]+1)*2 -1;			
		}
		//debug(power);
		for(int i = 0;i<totalCases;i++)
		{
			int x = ni();
			int y = ni();
			
			System.out.println(solve (x,y));						
		}
		
	}

	int solve(int x,int y) throws IOException	
	{
		//debug(x,y);
		if(x == 0)
			return y;
		else if(y == 0)
			return x;
		else if(x == 1)
		{
			if(y%2 == 0)
				return y+1;
			else
				return y-1;
		}
		else if(y == 1)
		{
			if(x%2 == 0)
				return x+1;
			else
				return x-1;
		}
		else
		{
			int a = find(x);
			int b = find(y);
			
			if(a==b)
				return solve(x-a-1,y-b-1);
			else if(a<b)
			{
				return solve(x,y-b-1)+b+1;
			}
			else
			{
				return a+1+solve(x-a-1,y);
			}
			
			
		}
		
	
	}
	int find(int c)
	{
	
		int k = Arrays.binarySearch(power,c);
	//debug(k);
		if(k>0)
			return power[k-1];
		else
			return power[(-1*k)-2];
		
	}
	

	


}


