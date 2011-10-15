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

        //take input from user
        Scanner sc = new Scanner(System.in);
        int testCases = Integer.parseInt(sc.nextLine());

        String s = null;
        int inputs[][] = new int[testCases][2];
        for (int i = 0; i < testCases; i++) {
            s = sc.nextLine();
            int j = 0;
            for (String subString : s.split(" ")) {
                inputs[i][j] = Integer.parseInt(subString);
                j++;
            }
        }
        BigInteger bi;
        //BigInteger outputs[]=new BigInteger[testCases];
        for (int i = 0; i < testCases; i++) {
            bi = new BigInteger("0");
            bi = bi.flipBit((int)Math.pow(2,inputs[i][0]));
            System.out.println(bi.mod(new BigInteger(String.valueOf(inputs[i][1]))));
        }
    }
}
