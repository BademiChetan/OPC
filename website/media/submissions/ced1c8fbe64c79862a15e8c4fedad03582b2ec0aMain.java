import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class main
{
	
	private  static BigInteger m,k,p;
	private static int t,i,n,l;
	public static void main(String[] args) throws Exception
	{
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());
		//m = new BigInteger("0");
		while(t>0)
		{
			
			

			StringTokenizer st = new StringTokenizer(br.readLine());
			
			i=Integer.parseInt(st.nextToken());
			l=Integer.parseInt(st.nextToken());
			//i++;
			m=BigInteger.valueOf(i);
			k=BigInteger.valueOf(l);
			p=BigInteger.valueOf(2);
			m=p.pow(i);
				
			
			
			System.out.println(p.modPow(m,k));
			t--;
		}
	}
	
        	

}
