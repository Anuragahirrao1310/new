import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class StudentUI extends JFrame {
    private JTextField nameField;
    private JTextField rollNoField;

    public StudentUI() {
        setTitle("Student Information");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 2));

        JLabel nameLabel = new JLabel("Name:");
        nameField = new JTextField();
        JLabel rollNoLabel = new JLabel("Roll No:");
        rollNoField = new JTextField();
        JButton submitButton = new JButton("Submit");

        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String rollNo = rollNoField.getText();
                if (!name.isEmpty() && !rollNo.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "Name: " + name + "\nRoll No: " + rollNo);
                } else {
                    JOptionPane.showMessageDialog(null, "Please enter both name and roll number!");
                }
            }
        });

        add(nameLabel);
        add(nameField);
        add(rollNoLabel);
        add(rollNoField);
        add(submitButton);

        setVisible(true);
    }

    public static void main(String[] args) {
        new StudentUI();
    }
}
