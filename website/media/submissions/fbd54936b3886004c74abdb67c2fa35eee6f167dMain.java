import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[])throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        while(T-- > 0){
            StringTokenizer tok = new StringTokenizer(in.readLine());
            int X = Integer.parseInt(tok.nextToken());
            int Y = Integer.parseInt(tok.nextToken());
            if((X == 0 && Y != 0) || (Y == 0 && X != 0))System.out.println("1");
            else{
                int max = Math.max(X, Y);
                int min = Math.min(X, Y);
                //the user has max/N colors assumed because that many colors are enough to paint rows & col distinctly according to question
                // so th paint point x, y
                // the user can use min of row or min of columns colors
            
                int result = max - min;
           
                System.out.println(result);
            }
        }
    }
}
