package LabAssignmentSeven;


import java.awt.*;
import java.applet.*;
public class First_Applet extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.blue);
        Font font = new Font("Arial", Font.BOLD, 16);
        g.setFont(font);
        g.drawString("This is My First Applet",60,110);
    }
}
