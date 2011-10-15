

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
	int totalCases, testNum;	
	

	void execute() throws IOException
	{
		totalCases = ni();
		for(testNum = 1; testNum <= totalCases; testNum++)
		{
			
			long N = ni();
			long k = ni();			
			/*int total = 0;
			while(true)
			{
				if(k%2) == 0
				{
					total++;
					k = k/2;
				}
				else
					break;
			}*/
			
					
			long a = k-phi(k);
			long b = a-phi(a);
			
			long c = N%b;
			long d = (1<<c)%a;
			long e = (1<<d)%k;
			//debug(N,k,a,b,c,d,e);
			
			System.out.println(e);
			
			
			
		}
	}
	long phi(long n)
	{
		int l = (int)Math.sqrt(n);
		long count = 0;
		for(int i = 1;i<=l;i++)
		{
			if(n%i == 0)
				count++;
		}
		if(l*l == n)
		{
			return count*2-2;
		}
		else
			return count*2-1;
	}
}


