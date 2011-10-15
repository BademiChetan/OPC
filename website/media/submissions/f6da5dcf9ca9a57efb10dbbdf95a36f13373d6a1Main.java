
//package two;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        while(T-- > 0){
            int n = Integer.parseInt(in.readLine());
            StringTokenizer tok = new StringTokenizer(in.readLine());
            int[] arr = new int[n];
            
            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(tok.nextToken());
            }
            
            int sum = 0;
            for(int i = 0; i < n ; i++){
                sum += sum + arr[i] - i;
            }
            
            if((sum % 2) == 0 )System.out.println("LOSE");
            else{
                System.out.println("WIN");
            }
        }
    }
}
