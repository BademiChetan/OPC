import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author root
 */
class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int T;
        int N;
        String str;
        int Q;
        int r = 0;
        int a[] = new int[50000];
        int b[] = new int[50000];
        int c[] = new int[50000];
        int  i = 0;
        int count = 0;
        String input[] = new String[10];
        int f = 0;
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr); 
        try {
            T = Integer.parseInt(in.readLine());
            if(T <= 10 && T >= 1){
                while(count < T){
                    N = Integer.parseInt(in.readLine());
                    if(N <= 50000 && N >= 1){
                        str = in.readLine();
                        Q = Integer.parseInt(in.readLine());
                        if(Q <= 50000 && Q >= 1){
                            for(i=0; i < Q; i++){
                                input = in.readLine().split(" ");
                                
                                a[i] = Integer.parseInt(input[0]);
                                b[i] = Integer.parseInt(input[1]);
                                r = subs(str, a[i], b[i]);
                                if(r == -1)
                                    continue;
                                c[i] = r;
                            }
                            for(f = 0; f < i; f++){
                                System.out.println(c[f]);
                            }
                        }
                    }
                    count++;
                }
            }
            
            
        } catch (IOException ex) {
            
        }

        
    }
    public static int subs(String str, int a, int b){
        int flag = 0;
        if(a >= 0 && a < str.length()){
            flag = 0;
        }
        else{
            return -1;
        }
        if(b >= a && b >= 0){
            flag = 0;
        }
        else{
            return -1;
        }
        if(a+b-1 < str.length()){
            flag = 0;
        }
        else{
            return -1;
        }
        int cnt = 0;
        if(a == b){
            b++;
        }
        String sub = str.substring(a, b);
           while(b <= str.length()){
               if(str.substring(a, b).equalsIgnoreCase(sub)){
                   cnt++;
               }
  
               b++;
               a++;

            }
            return cnt;
    }
}

