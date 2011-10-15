/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package Fortune;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Swarnim
 */
class Main {

    public static void main(String[] args) {
        try {
            //take input from user
            Scanner sc = new Scanner(System.in);
            int testCases = Integer.parseInt(sc.nextLine());

            String s = null;
            BigInteger inputs[][] = new BigInteger[testCases][2];

            for (int i = 0; i < testCases; i++) {
                s = sc.nextLine();
                int j = 0;
                for (String subString : s.split(" ")) {
                    inputs[i][j] = new BigInteger(subString);
                    j++;
                }
            }

            BigInteger bi;

            //BigInteger outputs[]=new BigInteger[testCases];
            for (int i = 0; i < testCases; i++) {
                bi = new BigInteger("0");

                bi = bi.flipBit((int) Math.pow(2, inputs[i][0].intValue()));
                System.out.println(bi.mod((inputs[i][1])));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}