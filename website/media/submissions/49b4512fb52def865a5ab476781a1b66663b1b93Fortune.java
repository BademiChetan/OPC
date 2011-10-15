import java.util.*;
import java.math.BigInteger;

class Fortune
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int i, j, N;
        N = Integer.parseInt(sc.nextLine());
        for(j=1;j<=N;j++)
        {
            int n=Integer.parseInt(sc.next()), k=Integer.parseInt(sc.next()) ;
            long value = 2;
        
            for(i=1;i<=n;i++)
            {
                value = value*value ; 
            }
        
            System.out.println(value%k);
        }
    }
}