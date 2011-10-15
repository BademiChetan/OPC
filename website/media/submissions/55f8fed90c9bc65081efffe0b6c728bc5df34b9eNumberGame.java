import java.util.*;
class NumberGame
{
    public static void main ( String []args )
    {
        
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( ), i, j, p,sum = 0;
        for ( i = 0; i < n; i++ )
        {
             p = sc.nextInt ( );
             sum = 0;
             for ( j = 0; j< p; j++ )
             {
                  sum+=sc.nextInt ( )-j;
             }
             if (sum%2 == 1 )
             System.out.println ( "WIN" );
             else
             System.out.println ( "LOSE" );
        }
    }
}
            