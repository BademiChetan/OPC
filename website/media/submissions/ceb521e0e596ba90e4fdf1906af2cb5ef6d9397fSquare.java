import java.awt.*; 
 import java.awt.event.*; 
 import javax.swing.*; 
 import java.awt.geom.*; 
 
 public class Square extends JApplet { 
   public static void main(String s[]) { 
         JFrame frame = new JFrame(); 
         frame.setTitle("square"); 
         frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
         JApplet applet = new  Square(); 
         applet.init(); 
         frame.getContentPane().add(applet); 
         frame.pack(); 
         frame.setVisible(true); 
   } 
 
   public void init() { 
         JPanel panel = new StrokePanel(); 
         getContentPane().add(panel); 
   } 
 } 
 
 class StrokePanel extends JPanel { 
   public StrokePanel() { 
         setPreferredSize(new Dimension(500, 400)); 
         setBackground(Color.white); 
  } 
 
   public void paintComponent(Graphics g) { 
         super.paintComponent(g); 
         Graphics2D g2 = (Graphics2D)g; 
         GeneralPath path = new GeneralPath(GeneralPath.WIND_EVEN_ODD); 
          
    
         g2.drawRect(200,100,100,100); 
   
 
           } 
 }