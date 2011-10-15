/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

//package fortune;

/**
 *
 * @author xerxes
 */
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.lang.*;

public class Main {

    BufferedReader reader;
    StringTokenizer token;


    public static void main(String[] args)throws IOException {
        Main ob = new Main();
        ob.run();
        System.exit(0);
    }

    public void run()throws IOException{
        reader = new BufferedReader(new InputStreamReader(System.in) );
        String ss = reader.readLine();
        int cases = nextI(ss);

        for(int i=0;i<cases;++i){
            token = new StringTokenizer( reader.readLine() );
            long N = nextL( token.nextToken() );
            long K = nextL( token.nextToken() );
            //System.out.println(N+" "+K);
            doRest(N,K);
        }
    }
    public void doRest(long N, long K)throws IOException{
           ArrayList< BigInteger> vt = find_circle(K);
           int sz = vt.size();
           N+=1;
           int indx = (int) ( (N % sz) !=0 ? N % sz : N);
           System.out.println( vt.get(indx-1)) ;
    }

    public ArrayList<BigInteger> find_circle(long K){
        ArrayList< BigInteger > vt = new ArrayList< BigInteger >();
        
        BigInteger y = BigInteger.valueOf(K);
        BigInteger x = BigInteger.valueOf( (long) 2);
        for(int i=1;  ; ++i ){
            BigInteger m = x.mod(y);
            if(vt.contains(m)==true){
                break;
            }
            vt.add(m);
            x = x.multiply(x);
        }
        return vt;
    }
    int nextI(String ss){
        return Integer.parseInt(ss);
    }
    long nextL(String ss){
        return Long.parseLong(ss);
    }

}
