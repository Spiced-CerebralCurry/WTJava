package JDBC;
import java.sql.*;

public class Selection {
    public static void main(String[] args) {
        String query="select * from information";
        try (
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:4306/student", "root", "");
        ){
            Statement stmt = conn.createStatement();
            ResultSet rs=stmt.executeQuery(query);
            while (rs.next()){
                int id=rs.getInt("id");
                String name=rs.getString("name");
                int marks=rs.getInt("marks");
                String branch=rs.getString("branch");
                System.out.println();
                System.out.println("=========");
                System.out.println("ID: "+id);
                System.out.println("name: "+name);
                System.out.println("marks: "+marks);
                System.out.println("branch: "+branch);
            }
            rs.close();
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

