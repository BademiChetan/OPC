package s2;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Scanner ss = new Scanner(System.in);
        int test = sc.nextInt();
        int content[] = new int[2];
        int number[] = new int[test];
        String qq[][] = new String[test][];
        int quer[] = new int[test];
        String str[] = new String[test];
        for (int v = 0; v < test; v++) {
            number[v] = sc.nextInt();
            str[v] = sc.next();
            quer[v] = sc.nextInt();
            qq[v] = new String[quer[v]];
            for (int s = 0; s < quer[v]; s++) {
                qq[v][s] = ss.nextLine();
            }
        }
        for (int x = 0; x < test; x++) {

            for (int c = 0; c < quer[x]; c++) {
                qq[x][c] = qq[x][c].trim();
                int len = qq[x][c].length();
                int b = 0;
                for (int d = 0; d < len; d++) {
                    if (qq[x][c].charAt(d) == ' ') {
                        content[0] = Integer.parseInt(qq[x][c].substring(b, d));
                        b = d + 1;

                    }
                }
                content[1] = Integer.parseInt(qq[x][c].substring(b, len));
                String sub = str[x].substring(content[0], content[0] + content[1]);
                int k = 0;
                for (int f = 0; f < str[x].length() - content[1]; f++) {
                    if (str[x].substring(f, f + content[1]).equals(sub)) {
                        k++;
                    }
                }
                System.out.println(k);
            }
        }
    }
}
