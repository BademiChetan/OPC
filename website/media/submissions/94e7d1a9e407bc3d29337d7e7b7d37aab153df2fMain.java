
//package three;

import java.util.*;
import java.io.*;
import java.math.BigInteger;
class Main {
    public static void main(String args[])throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        while(T-- > 0){
            StringTokenizer tok = new StringTokenizer(in.readLine());
            //int days = Integer.parseInt(tok.nextToken());
            //int mod = Integer.parseInt(tok.nextToken());
            
            //long money = 2; //initial money
            
            //for(int i = 1; i <= days; i++){
            //    money = (money * money) % mod;
            //}
            int N = Integer.parseInt(tok.nextToken());
            BigInteger mod = new BigInteger(tok.nextToken());
            BigInteger two = new BigInteger("2");
            int money = two.pow(two.pow(N).mod(mod).intValue()).mod(mod).intValue();
            
            System.out.println(money);
        }
    }
}
