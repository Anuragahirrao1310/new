import java.sql.*;

public class JDBCExample {
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost/your_database_name"; 

    static final String USER = "your_username"; 
    static final String PASS = "your_password"; 

    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        try {
            // Register JDBC driver
            Class.forName(JDBC_DRIVER);

            // Open a connection
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            // Create a statement
            System.out.println("Creating statement...");
            stmt = conn.createStatement();

            // Execute insert query
            String sql = "INSERT INTO students VALUES (101, 'John', 90.5)";
            stmt.executeUpdate(sql);
            System.out.println("Inserted record into the table...");

            // Execute delete query
            sql = "DELETE FROM students WHERE id = 101";
            stmt.executeUpdate(sql);
            System.out.println("Deleted record from the table...");

            // Execute update query
            sql = "UPDATE students SET name = 'Alice' WHERE id = 102";
            stmt.executeUpdate(sql);
            System.out.println("Updated record in the table...");

            // Execute select query
            sql = "SELECT id, name, marks FROM students";
            ResultSet rs = stmt.executeQuery(sql);

            // Extract data from result set
            while (rs.next()) {
                // Retrieve by column name
                int id = rs.getInt("id");
                String name = rs.getString("name");
                double marks = rs.getDouble("marks");

                // Display values
                System.out.print("ID: " + id);
                System.out.print(", Name: " + name);
                System.out.println(", Marks: " + marks);
            }
            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException se) {
            // Handle errors for JDBC
            se.printStackTrace();
        } catch (Exception e) {
            // Handle errors for Class.forName
            e.printStackTrace();
        } finally {
            // Finally block used to close resources
            try {
                if (stmt != null) stmt.close();
            } catch (SQLException se2) {
            } // nothing we can do
            try {
                if (conn != null) conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            } // end finally try
        } // end try
        System.out.println("Goodbye!");
    } // end main
}
