import java.io.*;
import java.util.*;
class CountingStrings
{
    public static void main ( String []args )
    {
        String s = "abcabc";
        int n, t, m, k, i , j, q;
        String s2 = "";

        CountingStrings obj = new CountingStrings ( );
        
        Scanner sc = new Scanner ( System.in );
        String input = "";
        try
         {	//to make sure a valid intger choice has been entered.
			//	input = sc.next( );//inputting the choice
			System.out.print ( "" );
				t = Integer.parseInt ( sc.nextLine( ) );
				//System.out.println ( t );
				for ( i = 0; i < t; i++ )
				{
				    n = Integer.parseInt ( sc.nextLine ( ) );
				    
				    s = sc.nextLine ( );
				    q = Integer.parseInt ( sc.nextLine ( ) );
				    for ( j = 0; j < q; j++ )
				    { 
				        s2= sc.nextLine ( );
				        m = s2.charAt ( 0 ) - 48;
				        k = s2.charAt ( 2 ) - 48;
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
