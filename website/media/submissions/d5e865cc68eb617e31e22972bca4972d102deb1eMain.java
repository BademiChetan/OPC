import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Main {

	public static void main(String[] args) {
		
//		String strLine="abcabc";
//		String subStr="ab";
		
		StringBuffer sb;
		
		String strLine, subStr, str;		
		
		Pattern pattern;
		Matcher matcher;
		
		    
		       Scanner sc = new Scanner(System.in);
		       int t = sc.nextInt();
		       int n, q;
		       int m, k, end;
		       int i=0, j=0;
		       
		       int count = 0;
		       
		       while(i<t)
		       {
		    	   n = sc.nextInt();
//		    	   sb.setLength(n);
		    	   sb = new StringBuffer(n);		    	   
		    	   str = sc.next();
		    	   sb.append(str);
		    	   strLine = sb.toString();
		    	   
		    	   q = sc.nextInt();

		    	   while(j<q)
		    	   {
		    		   m = sc.nextInt();
		    		   k = sc.nextInt();
		    		   end = m + k;
		    		   
		    		   subStr = strLine.substring(m, end);
		    		   //System.out.println(subStr);
		    		   
		    		   pattern = Pattern.compile(subStr);
		    		   matcher = pattern.matcher(strLine);
		    		   
		    		   while(matcher.find()) {
//		    			   if(matcher.start()>m)
//		    			   {
		    				   count++;
//		    			   }
				       }
		    		   
		    		   j++;		    		   
		    		   System.out.println(count);
		    		   count = 0;
		    	   }
		    	   
		    	   i++;
		       }

	}

}
