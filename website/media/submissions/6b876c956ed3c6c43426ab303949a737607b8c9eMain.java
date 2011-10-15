import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    String s;
	    s = in.readLine();
	    int i = 0;
	    int t = Integer.parseInt(s);
	    while(i < t)
	    {
	    	s = in.readLine();
	    	String[] inp = s.split(" ");
	    	int x = Integer.parseInt(inp[0]);
	    	int a = x;
	    	int y = Integer.parseInt(inp[1]);
	    	boolean isRowOdd = (x % 2 == 1);
	    	
	    	if(isRowOdd) --a;
	    	long q = 0;
	    	if(a != 0)
	    		q = y/a;
	    	long res = 0;
	    	if(a > 0)
	    	{
	    		if(q % 2 == 0)
	    		{
	    			res = a *(q + 1) + ((y % a));
	    		}
	    		else
	    			res = a *(q - 1) + ((y % a));
	    	}
	    	else
	    	{
	    		if(q % 2 == 0)
	    		{
	    			res = y;
	    		}
	    		else
	    			res = y;
	    	}
	    	if(isRowOdd)
	    	{
	    		if(y % 2 == 0) System.out.println(res + 1);
	    		else System.out.println(res - 1);
	    	}	
	    	else
	    		System.out.println(res);
	    	++i;
	    }
	}
}
