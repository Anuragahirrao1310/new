import java.awt.Button;
import java.awt.Frame;

public class AWTExample {
    public static void main(String[] args) {
        // Create a frame
        Frame frame = new Frame("AWT Example");

        // Create a button
        Button button = new Button("Click Me");

        // Set the button's size
        button.setBounds(100, 100, 80, 30); // (x, y, width, height)

        // Add the button to the frame
        frame.add(button);

        // Set frame size
        frame.setSize(300, 200); // width, height

        // Set frame layout (null layout for absolute positioning)
        frame.setLayout(null);

        // Make the frame visible
        frame.setVisible(true);
    }
}
