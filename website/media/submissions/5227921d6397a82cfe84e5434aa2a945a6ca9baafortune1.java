import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *
 * @author root
 */
class fortune {
    public static void main(String[] args) {
        int T;
        Long N, K;
	double ans[];
	int l = 0, m = 0;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        String input[] = new String[10];
        try {
            T = Integer.parseInt(in.readLine());
            if(1 <= T && T <= 1000 ){
		ans = new double[T];
                while(T > 0){
                    input = in.readLine().split(" ");
                    N = Long.valueOf(input[0]);
                    if(1<= N&& N <= 1000000000){
                        K = Long.valueOf(input[1]);
                        if(1<= K&& K <= 1000000000){
                            if(K%2 != 0){
                                ans[l] = sqr1(N,K);
                                l++;
                            }
                        }
                    }
                    T--;
                }
                while(l >= 0){
                    System.out.println((int)ans[m]);
                    m++;
                }

            }
            }catch(Exception e){
        }
    }
    public static double sqr1(Long a, Long b){
        long r = 2;
        long result = 0;
        while(a > 0){
            r = r * r;
            a--;
        }
        result = r%b;
        return result;
    }
}