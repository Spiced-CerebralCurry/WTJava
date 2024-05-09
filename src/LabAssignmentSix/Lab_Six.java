package LabAssignmentSix;

import java.util.*;

public class Lab_Six{
    public static void main(String[] args) {
        int n;
        int sum = 0;
        String s;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter value with one space gap");
        s = sc.nextLine();
        StringTokenizer stringTokenizer = new StringTokenizer(s, " ");
        while (stringTokenizer.hasMoreTokens()) {
            String s1 = stringTokenizer.nextToken();
            n = Integer.parseInt(s1);
            sum = sum + n;
        }
        System.out.println("sum=" + sum);
    }
}
