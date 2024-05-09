package LabAssignmentFour;

import java.util.Scanner;

class Values{
    int r,h,l;
    double pi=Math.PI;
    Scanner sc=new Scanner(System.in);
    public void getvalues() {
        System.out.println("enter value of radius");
        r= sc.nextInt();
        System.out.println("enter value of length");
        l= sc.nextInt();
        System.out.println("enter value of height");
        h= sc.nextInt();
    }
    public void set(int r,int l,int h) {
        this.l=l;
        this.r=r;
        this.h=h;
    }
}
class Area extends Values{
    void circle() {
        double area=pi*(double)r*(double)r;
        System.out.println("area of circle is "+area);
    }
    void rectangle() {
        int area=l*h;
        System.out.println("area of rectangle is "+area);
    }
    void square() {
        int area= l*l*l;
        System.out.println("area of square is "+area);
    }
    void cylinder() {
        double area=2*pi*(double)r*((double)r+h);
        System.out.println("area of cylinder is "+area);
    }
}
public class AreaOfShape {
    public static void main(String[] args) {
        Area a1=new Area();
        a1.getvalues();
        a1.circle();
        a1.cylinder();
        a1.rectangle();
        a1.square();

    }
}
