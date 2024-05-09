package LabAssignmentTwo;

import java.util.Scanner;

class GetValues{
    Scanner sc = new Scanner(System.in);
    public int getNum() {
        System.out.print("Enter a positive integer: ");
        int num = sc.nextInt();
        return num;
    }
}

class Fibo extends GetValues{
    public int fib(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fib(n - 1) + fib(n - 2);
        }
    }
}

public class Fibbonacci {
    public static void main(String[] args) {
        Fibo f = new Fibo();
        int num=f.getNum();

        int result = f.fib(num);
        System.out.println("The " + num + "th Fibonacci number is: " + result);
    }
}

