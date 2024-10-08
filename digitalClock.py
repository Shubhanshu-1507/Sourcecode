import tkinter as tk
import time

# Function to update the time on the digital clock
def update_time():
    current_time = time.strftime('%H:%M:%S')  # Get the current time in HH:MM:SS format
    label.config(text=current_time)  # Update the label with the current time
    root.after(1000, update_time)  # Schedule the function to be called again after 1 second

# Create the main window
root = tk.Tk()
root.title('Digital Clock')

# Create a label widget to display the time
label = tk.Label(root, font=('calibri', 40, 'bold'), background='black', foreground='white')

# Pack the label widget into the window
label.pack(anchor='center')

# Call the update_time function to start updating the clock
update_time()

# Run the Tkinter event loop
root.mainloop()
