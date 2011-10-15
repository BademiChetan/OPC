
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *
 * @author root
 */
class fortune {
    public static void main(String[] args) {
        long N, K, T;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        String input[] = new String[10];
        try {
            T = Long.valueOf(in.readLine());
            if(1 <= T && T <= 1000 ){
                while(T > 0){
                    input = in.readLine().split(" ");
                    N = Long.valueOf(input[0]);
                    if(1<= N&& N <= 1000000000){
                        K = Long.valueOf(input[1]);
                        if(1<= K&& K <= 1000000000){
                            if(K%2 != 0){
                                sqr1(N,K);
                            }
                        }
                    }
                    T--;
                }

            }
            }catch(Exception e){
        }
    }
    public static void sqr1(long a, long b){
        long r = 2;
        long result = 0;
        while(a > 0){
            r = r * r;
            a--;
        }
        result = r%b;
        System.out.println(result);
    }
}
