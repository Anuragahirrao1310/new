import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class StudentTable extends JFrame {
    private DefaultTableModel model;
    private JTable table;

    public StudentTable() {
        setTitle("Student Details");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create table model with column names
        model = new DefaultTableModel();
        model.addColumn("Roll Number");
        model.addColumn("Name");
        model.addColumn("Percentage");

        // Create table with model
        table = new JTable(model);
        JScrollPane scrollPane = new JScrollPane(table);

        // Add table to frame
        add(scrollPane);

        // Insert values into the table
        insertDataIntoTable();

        // Display frame
        setVisible(true);
    }

    private void insertDataIntoTable() {
        // Sample student data
        Object[][] data = {
                {1, "Alice", 85.5},
                {2, "Bob", 78.2},
                {3, "Charlie", 92.3},
                {4, "David", 67.8},
                {5, "Eve", 89.6}
        };

        // Insert data into the table model
        for (Object[] row : data) {
            model.addRow(row);
        }
    }

    public static void main(String[] args) {
        // Create and show the GUI
        SwingUtilities.invokeLater(() -> new StudentTable());
    }
}
