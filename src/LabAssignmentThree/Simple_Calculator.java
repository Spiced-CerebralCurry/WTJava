package LabAssignmentThree;

import java.util.Scanner;

public class Simple_Calculator {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the first value");
        int a=sc.nextInt();
        System.out.println("Enter the second value");
        int b=sc.nextInt();
        System.out.println("Enter " +
                " 1.to do addition of two numbers" +
                " 2.to perform subtraction" +
                " 3.to perform multiplication"+
                " 4.to perform division ");
        System.out.println("Enter the choice");
        int ch=sc.nextInt();
        switch(ch)
        {
            case 1:
                int sum=a+b;
                System.out.println("sum is "+sum);
                break;
            case 2:
                int sub=a-b;
                System.out.println("subtraction is "+sub);
                break;
            case 3:
                int mul=a*b;
                System.out.println("multiplication is "+mul);
                break;
            case 4:
                int div=a/b;
                System.out.println("division is "+div);
                break;
            default:
                System.out.println("Invalid input");

        }
    }
}

