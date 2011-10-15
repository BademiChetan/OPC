import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class MainT {

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
	    	int n = Integer.parseInt(s);
	    	int turnTotal = (n * (n - 1))/2;
	    	s = in.readLine();
	    	String[] inp = s.split(" ");
	    	int sum = 0;
	    	for(int j = 0; j < inp.length; ++j)
	    	{
	    		sum += Integer.parseInt(inp[j]);
	    	}
	    	int res = sum - turnTotal;
	    	if(res % 2 == 0 )
	    		System.out.println("LOSE");
	    	else
	    		System.out.println("WIN");
	    	++i;
	    }
	}
}