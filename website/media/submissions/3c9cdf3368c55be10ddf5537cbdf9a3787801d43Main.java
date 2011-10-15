/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author root
 */
class Main {

    public static String getResult(Point p) {
        int count = p.x + p.y;

        if((count/2)%2 == 0){
            if(count%2 == 0){
                if(p.y%2 == 0)
                    return "LOSE";
                else
                    return "WIN";
            } else {
                if(p.y%2 == 0)
                    return "WIN";
                else
                    return "LOSE";
            }
        } else {
            if(count%2 == 0){
                if(p.y%2 == 0)
                    return "WIN";
                else
                    return "LOSE";
            } else {
                if(p.y%2 == 0)
                    return "LOSE";
                else
                    return "WIN";
            }                
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BufferedReader dis = new BufferedReader(new InputStreamReader(System.in));

        int no = 0;
        try {
            //    BufferedReader dis = new BufferedReader(new FileReader(new File(args[0])));
            no = Integer.parseInt(dis.readLine());
            Point pts[] = new Point[no];

            for (int i = 0; i < no; i++) {
                int even = 0, odd = 0;
                String str = dis.readLine();
                StringTokenizer tok = new StringTokenizer(str, " ");
                while (tok.hasMoreTokens()) {
                    if (Integer.parseInt(tok.nextToken()) % 2 == 0) {
                        even++;
                    } else {
                        odd++;
                    }
                }
                pts[i] = new Point(even,odd);
            }

            for (int i = 0; i < no; i++) {
                System.out.println(getResult(pts[i]));
            }

        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
