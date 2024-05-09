package JDBC;

import java.sql.*;

public class Updation {
    public static void main(String[] args) {
        String query="update information "+ " set marks=29 "+" where id=101";
        try (
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:4306/student", "root", "");
        ){
            Statement stmt = conn.createStatement();
            int rowsaffected=stmt.executeUpdate(query);
            if(rowsaffected>0){
                System.out.println("Updation successful "+rowsaffected+" row(s) affected");
            }
            else{
                System.out.println("Updation failed");
            }
            stmt.close();
            conn.close();
            System.out.println();
            System.out.println("connection closed successfully");
        }
        catch (Exception e){
            System.out.println("error"+e);
        }
    }
}


