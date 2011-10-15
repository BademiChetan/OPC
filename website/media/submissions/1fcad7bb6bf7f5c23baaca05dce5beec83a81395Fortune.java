import java.math.BigInteger;
import java.util.*;

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
            String t = "" + k + "";
            BigInteger[] answers = new BigInteger[k];
            BigInteger x = new BigInteger("0");
            BigInteger value = new BigInteger("2");
            BigInteger bk = new BigInteger(t);
            boolean flag = false;
            for(i=0;i<k;i++)
            {
                value = value.multiply(value);
                answers[i] = value.mod(bk) ; 
                if(end(answers, i))
                    break;
            }
            
            if(n<=i)
                System.out.println(answers[(n-1)%i]);
            else
                System.out.println(answers[n%i]);
        }
    }
    
    public static boolean end(BigInteger answers[], int pos)
    {
        int i;
        
        for(i=0;i<pos;i++)
        {
            if(answers[i].compareTo(answers[pos]) == 0)
                return true;
        }
        return false;
    }
}
