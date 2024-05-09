package JDBC;

import java.sql.*;
public class Insertion {
    public static void main(String[] args) {
        try (
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:4306/student", "root", "");
        ){
            String query="insert into information(id,name,marks,branch) values (103,'Anuja',24,'Arts')";
            Statement stmt = conn.createStatement();
            int rowsaffected=stmt.executeUpdate(query);
            if(rowsaffected>0){
                System.out.println("Insertion successful "+rowsaffected+" row(s) affected");
            }
            else{
                System.out.println("Insertion failed");
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
