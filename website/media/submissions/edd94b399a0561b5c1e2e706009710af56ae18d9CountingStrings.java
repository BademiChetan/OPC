
import java.util.*;
class CountingStrings
{
    public static void main ( String []args )
    {
        String s = "";
        String s3 = "";
        int  t = 0, m = 0, k = 0, i = 0 , j = 0 , q = 0, x;
        int count = 0;
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
                        s2= sc.nextLine ( );
                        StringTokenizer st = new StringTokenizer ( s2 );
                        m = Integer.parseInt (st.nextToken ( ) );
                        k =  Integer.parseInt (st.nextToken ( ) );
                        s2 = s + "";
//                      obj. print ( s2, m, k );
                        count = 0;
        
        s3 = s2.substring ( m, m+k );
        x = s2.indexOf ( s3 );
        while (x >= 0 && s2.length ( ) > 0)
        {   
            count++;
            
            s2 = s2.substring ( x+k );
            x = s2.indexOf ( s3 );
        }
        System.out.println ( count );


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
