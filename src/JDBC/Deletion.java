package JDBC;

import java.sql.*;

public class Deletion {
    public static void main(String[] args) {
        String query="DELETE FROM information where id=103";
        try (
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:4306/student", "root", "");
        ){
            Statement stmt = conn.createStatement();
            int rowsaffected=stmt.executeUpdate(query);
            if(rowsaffected>0){
                System.out.println("Deletion successful "+rowsaffected+" row(s) affected");
            }
            else{
                System.out.println("Deletion failed");
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
