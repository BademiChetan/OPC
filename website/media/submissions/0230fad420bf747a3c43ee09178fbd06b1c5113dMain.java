/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

//package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 *
 * @author susheel
 */
 class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputStr="";
        int numberOfTests = 0;
        String n="",k="";

        try
        {
            inputStr = br.readLine();
            numberOfTests = Integer.parseInt(inputStr);
            inputStr = br.readLine();

            while(inputStr.length() > 0)
            {
   
                StringTokenizer st = new StringTokenizer(inputStr, " ");

                if(st.hasMoreTokens())
                {
                    n = st.nextToken();
                    k = st.nextToken();
                    int intn = Integer.parseInt(n);

                   
                    BigInteger bigK = new BigInteger(k);

                    BigInteger big2 = new BigInteger("2");
                   

                    BigInteger bigOut = big2.pow(intn);
                    bigOut = big2.modPow(bigOut, bigK);

                    //output = Math.pow(2,n);
                    //output = Math.pow(2,output);

                    System.out.println(bigOut.toString());
                    numberOfTests--;
                    
                }

                inputStr = br.readLine();
            }
        }catch(Exception e)
        {}


    }

}
