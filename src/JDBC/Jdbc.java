package JDBC;

import java.sql.Connection;
import java.sql.DriverManager;


public class Jdbc {
    public static void main(String[] args) {
        try {
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:4306/student", "root", "");
            System.out.println(connection);
        }
        catch (Exception e){
            System.out.println("error"+e);
        }
    }
}
