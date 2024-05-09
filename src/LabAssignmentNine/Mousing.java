package LabAssignmentNine;

import javax.swing.*;
import java.awt.*;

public class Mousing {
    static JFrame frame;
    static JTextField text;
    static JLabel tsts;
    //Driver function
    public static void main(String[] args) {
        System.out.println("Hello");

        //Create a Frame
        frame=new JFrame("Display Event");
        frame.setBackground(Color.BLUE);
        frame.setSize(400,400);
        frame.setLayout(null);


        //Create a TextField
       /* text=new JTextField();
        text.setBounds(5,5,500,50);
        text.setBackground(Color.cyan);
        text.setText("PANI PAANI");
        frame.add(text);*/

        tsts= new JLabel();
        tsts.setBounds(5,5,500,50);
        tsts.setText("TATA");
        tsts.setBackground(Color.cyan);
        frame.add(tsts);
        //Display frame
        frame.setVisible(true);
    }
}
