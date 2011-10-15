import java.io.DataInputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author root
 */
public class counting {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int T;
        int N;
        String str;
        int Q;
        int a[] = new int[50000];
        int b[] = new int[50000];
        int c[] = new int[50000];
        int M, K;
        int  i = 0;
        int count = 0;
        String input[] = new String[10];
        int f = 0;
        DataInputStream in = new DataInputStream(System.in); 
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
                                b[i] = Integer.parseInt(input[0]);
                                c[i] = subs(str, a[i], b[i]);
                            }
                            for(f = 0; f < i; f++){
                                System.out.println(c[f]);
                            }
                        }
                    }
                }
            }
            
            
        } catch (IOException ex) {
            
        }

        
    }
    public static int subs(String str, int a, int b){
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
