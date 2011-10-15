//import java.lang.*;
import java.io.*;

class p1
{
   public static void main(String args[])throws IOException
   {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       System.out.println("enter the string test cases");
       int tc=Integer.parseInt(br.readLine());
       String arr[]=new String[tc];
	int i=0;
        while(i<tc)
       {
	   System.out.println("enter length of string");
	   int l=Integer.parseInt(br.readLine());
           System.out.println("enter a string ");
           arr[i]=br.readLine();
           if(arr[i].length()!=l)
	   {
		System.out.println("error in entering");
               arr[i]="";
	       continue;
            }
	   System.out.println("enter the no of query");
	   int q=Integer.parseInt(br.readLine());
	   int qarr[][]=new int [q][2];
           for(int j=0;j<q;j++)
           {
	      
	      for(int k=0;k<2;k++)
	      {
	         System.out.println("enter starting index and length of string");
		 qarr[j][k]=Integer.parseInt(br.readLine());
	      }

	   }
         int c[]=new int[q];
	 int ct=0;  
	for(int x=0;x<q;x++)
	{
	 
            int y=0;	
	    String s=arr[i].substring(qarr[x][y],qarr[x][y+1]);
	    int l1=s.length();
            for(int m=0;m<arr[i].length()-2;m++)
            {
              String s1=arr[i].substring(m,l1+m);
              if(s.compareTo(s1)==0)
               ct++;

            }
          
            
               c[x]=ct;
               ct=0;

         } 

       for(int z=0;z<q;z++)
        System.out.println(c[z]);  
                 //int si=Integer.parseInt(br.readLine());
	         //int sl=Integer.parseInt(br.readLine());
              
	      
            i++;
        }


}

}
	       
       