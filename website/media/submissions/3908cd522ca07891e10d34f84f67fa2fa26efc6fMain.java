import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Main
 {
	public static void main(String args[])
	 {
		Scanner sc=new Scanner(System.in);
		int t, i;
		BigInteger n, k, j;

		t=sc.nextInt();
		for(i=0;i<t;i++)
		 {
			n=sc.nextBigInteger();
			k=sc.nextBigInteger();
			BigInteger result=new BigInteger("2");

			for(j=BigInteger.ONE;j.compareTo(n)<=0;j=j.add(BigInteger.ONE))
				result=result.pow(2);
			System.out.println(result.remainder(BigInteger.valueOf(99)));
		 }
	 }
 }