import java.util.*;

class Fortune
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int i, j, N;
        N = Integer.parseInt(sc.nextLine());
        long []answers = new long[4];
        for(j=1;j<=N;j++)
        {
            int n=Integer.parseInt(sc.next()), k=Integer.parseInt(sc.next()) ;
            long value = 2;
        
            for(i=0;i<4;i++)
            {
                value = value*value;
                answers[i] = value%k ; 
            }
        
            System.out.println(answers[(n-1)%4]);
        }
    }
}
