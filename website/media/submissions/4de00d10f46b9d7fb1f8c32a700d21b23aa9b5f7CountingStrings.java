
import java.util.*;
class CountingStrings
{
    public static void main ( String []args )
    {
        String s = "abcabc";
        int  t = 0, m = 0, k = 0, i = 0 , j = 0 , q = 0;
        String s2 = "";

        CountingStrings obj = new CountingStrings ( );
        
        Scanner sc = new Scanner ( System.in );
        try
         {	
			System.out.print ( "" );
				t = Integer.parseInt ( sc.nextLine( ) );
				for ( i = 0; i < t; i++ )
				{
				   
				    s = sc.nextLine ( );
				    s = sc.nextLine ( );
				    q = Integer.parseInt ( sc.nextLine ( ) );
				    for ( j = 0; j < q; j++ )
				    { 
				        
				        m = sc.nextInt ( );
				        k = sc.nextInt ( );
				        s2 = s + "";
				        obj. print ( s2, m, k );
				    }
				}
				    
				
				
				
				
   		
			}
			catch ( Exception e )
			{
			System.out.println ( "wth" );
			}
        
            
    }
    
    
    public void print ( String s, int m, int k )
    {
        
        int count = 0;
        String s2 = s.substring ( m, m+k );
        while (s.indexOf ( s2 ) >= 0 && s.length ( ) > 0)
        {   
            count++;
            s = s.substring ( s.indexOf ( s2 )+k );
        }
        System.out.println ( count );
    }
        
}