/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package shaastra1;

import java.awt.Point;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author root
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static int getColor(Point p) {
        if(p.x == p.y)
            return 0;

        if(p.x < p.y){
            int tmp = p.x;
            p.x = p.y;
            p.y= tmp;
        }

        if(p.x % 2 == 0){
            return p.x + p.y;
        } else {
            return p.x - p.y;
        }
    }

    public static void main(String[] args) {
        DataInputStream dis = new DataInputStream(System.in);
        int no = 0;
        try {
            no = Integer.parseInt(dis.readLine());
            Point pts[] = new Point[no];

            for (int i = 0; i < no; i++) {
                String str = dis.readLine();
                StringTokenizer tok = new StringTokenizer(str, " ");
                int x = Integer.parseInt(tok.nextToken());
                int y = Integer.parseInt(tok.nextToken());
                pts[i] = new Point(x,y);
            }

            for (int i = 0; i < no; i++) {
                System.out.println(getColor(pts[i]));
            }

        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
