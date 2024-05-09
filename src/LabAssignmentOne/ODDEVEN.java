package LabAssignmentOne;

import java.util.Scanner;

    class GET{
        int a;
        Scanner sc=new Scanner(System.in);
        public void getA() {
            System.out.println("enter value of a");
            a= sc.nextInt();
        }
    }

    class Check extends GET{
        void checkfun() {
            if ((a%2)==0) {
                System.out.println(a+" is even");
            } else {
                System.out.println(a + " is odd");
            }
        }
    }

    public class ODDEVEN {
        public static void main(String[] args) {
            Check c1=new Check();
            c1.getA();
            c1.checkfun();
        }
    }