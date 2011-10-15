import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[])throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        while(T-- > 0){
            int strLength = Integer.parseInt(in.readLine());
            String str = in.readLine();
            
            int inputs = Integer.parseInt(in.readLine());
            while(inputs-- > 0){
                StringTokenizer tok = new StringTokenizer(in.readLine());
                int start = Integer.parseInt(tok.nextToken());
                int end = start + Integer.parseInt(tok.nextToken());
                int count = 0;
                
                String substr = str.substring(start, end);
                
                for(int i = 0; i <= strLength - substr.length(); i++){
                    if(substr.equals(str.substring(i, (i + substr.length())))){
                        count++;
                    }
                }
                 System.out.println(count);
            }
           
        }
    }
}
