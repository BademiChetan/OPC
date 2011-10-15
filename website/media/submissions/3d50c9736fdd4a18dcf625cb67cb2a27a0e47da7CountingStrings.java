
import java.util.*;
class CountingStrings
{
    public static void main ( String []args ) throws Exception
    {
        String s = "abcabc";
        int  t = 0, m = 0, k = 0, i = 0 , j = 0 , q = 0;
        String s2 = "";

        CountingStrings obj = new CountingStrings ( );
        
        Scanner sc = new Scanner ( System.in );
       	
			System.out.print ( "" );
				t = Integer.parseInt ( sc.nextLine( ) );
				for ( i = 0; i < t; i++ )
				{
				   
				    s = sc.nextLine ( );
				    s = sc.nextLine ( );
				    q = Integer.parseInt ( sc.nextLine ( ) );
				    for ( j = 0; j < q; j++ )
				    { 
				        s2= sc.nextLine ( );
				        StringTokenizer st = new StringTokenizer ( s2 );
				        m = Integer.parseInt (st.nextToken ( ) );
				        k =  Integer.parseInt (st.nextToken ( ) );
				        s2 = s + "";
				        obj. print ( s2, m, k );
				    }
				}
				    
				
				
				
				
   		
			
            
    }
    
    
    public void print ( String s, int m, int k )
    {
        
        int count = 0;
        
        String s2 = s.substring ( m, m+k );
        int x = s.indexOf ( s2 );
        while (x >= 0 && s.length ( ) > 0)
        {   
            count++;
            
            s = s.substring ( x+k );
            x = s.indexOf ( s2 );
        }
        System.out.println ( count );
    }
        
}
