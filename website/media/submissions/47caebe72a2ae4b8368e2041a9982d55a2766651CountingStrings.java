import java.io.*;
import java.util.*;
public class CountingStrings
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
				System.out.println ( t );
				for ( i = 0; i < t; i++ )
				{
				    n = Integer.parseInt ( sc.nextLine ( ) );
				  //  System.out.println ( n);
				    
				    s = sc.nextLine ( );
				   // System.out.println ( s);
				    q = Integer.parseInt ( sc.nextLine ( ) );
				   // System.out.println ( q);
				    for ( j = 0; j < q; j++ )
				    { //  System.out.println  ("blah" );
				        s2= sc.nextLine ( );
				        m = s2.charAt ( 0 ) - 48;
				        k = s2.charAt ( 2 ) - 48;
				      //  m = Integer.parseInt ( sc.nextLine ( ) );
				       // System.out.println ( m);
				      //  k = Integer.parseInt ( sc.nextLine ( ) );
				       // System.out.println ( k);
				        //System.out.print ( "yo");
				        s2 = s + "";
				        obj. print ( s2, m, k );
				        //System.out.print ( "yo" );
				    }
				}
				    
				
				
				
				
   		
			}
			catch ( Exception e )
			{
			System.out.println ( "wth" );
			}
        
        //obj.print ( s, 0,3 );
            
    }
    
    
    public void print ( String s, int m, int k )
    {
        //System.out.println ( "yes" );
        
        int count = 0;
        String s2 = s.substring ( m, m+k );
        //System.out.println ( s2 );
        while (s.indexOf ( s2 ) >= 0 && s.length ( ) > 0)
        {   
          //  System.out.print ( s );
            count++;
            s = s.substring ( s.indexOf ( s2 )+k );
            //System.out.println ( count + s );
        }
        System.out.println ( count );
    }
        
}
