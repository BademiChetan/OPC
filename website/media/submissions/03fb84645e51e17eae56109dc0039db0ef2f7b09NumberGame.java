import java.util.*;
class NumberGame
{
    public static void main ( String []args )
    {
        
        Scanner sc = new Scanner ( System.in );
        int n = Integer.parseInt ( sc.nextLine( ) ), i, j, p,sum = 0;
        String s = "";
        for ( i = 0; i < n; i++ )
        {
             p = Integer.parseInt ( sc.nextLine( ) );
             sum = 0;
             s = sc.nextLine ( );
             StringTokenizer st = new StringTokenizer ( s );
             for ( j = 0; j< p; j++ )
             {
                  sum+=Integer.parseInt ( st.nextToken( ) )-j;
             }
             if (sum%2 == 1 )
             System.out.println ( "WIN" );
             else
             System.out.println ( "LOSE" );
        }
    }
}
            