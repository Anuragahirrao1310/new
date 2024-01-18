import tkinter as tk

# Function to save student details to a file
def save_student():
    name = entry_name.get()
    roll = entry_roll.get()
    with open("student_details.txt", "a") as file:
        file.write(f"Name: {name}\tRoll: {roll}\n")
    entry_name.delete(0, 'end')
    entry_roll.delete(0, 'end')

# Function to read and display student details from the file
def read_student():
    text.delete(1.0, 'end')
    with open("student_details.txt", "r") as file:
        data = file.read()
        text.insert('end', data)

# Create the main window
root = tk.Tk()
root.title("Student Registration")

# Create and configure widgets
label_name = tk.Label(root, text="Name:")
entry_name = tk.Entry(root)
label_roll = tk.Label(root, text="Roll:")
entry_roll = tk.Entry(root)

button_save = tk.Button(root, text="Save", command=save_student)
button_read = tk.Button(root, text="Read", command=read_student)

text = tk.Text(root, height=10, width=40)

# Pack widgets
label_name.pack()
entry_name.pack()
label_roll.pack()
entry_roll.pack()
button_save.pack()
button_read.pack()
text.pack()

# Start the GUI event loop
root.mainloop()
