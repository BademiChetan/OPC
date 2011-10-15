import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Main
 {
	public static void main(String args[]) throws Exception
	 {
		BufferedReader ref=new BufferedReader(new InputStreamReader(System.in));
		int t, i;
		BigInteger j, n, k;
		String temp[]=null;
		String s;

		s=ref.readLine();
		t=Integer.valueOf(s);
		for(i=0;i<t;i++)
		 {
			s=ref.readLine();
			temp=s.split(" ");

			n=new BigInteger(temp[0]);
			k=new BigInteger(temp[1]);

			BigInteger result=new BigInteger("2");

			for(j=BigInteger.ONE;j.compareTo(n)<=0;j=j.add(BigInteger.ONE))
				result=result.pow(2);
			System.out.println(result.remainder(BigInteger.valueOf(99)));
		 }
	 }
 }