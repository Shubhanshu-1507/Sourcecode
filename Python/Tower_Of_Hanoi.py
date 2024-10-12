import tkinter as tk
from tkinter import Canvas, Frame, Button, simpledialog

class TowerOfHanoi(tk.Tk):
    def __init__(self, disks=3, pegs=3):
        super().__init__()
        self.title("Tower of Hanoi")
        self.disks = disks
        self.pegs = pegs
        self.peg_width = 10
        self.disk_height = 20
        self.canvas_height = self.disk_height * (self.disks + 5)
        self.canvas_width = 700
        self.moves = 0
        self.setup_game()
        self.create_widgets()

    def setup_game(self):
        self.pegs_list = [[] for _ in range(self.pegs)]
        self.selected_disk = None
        for i in range(self.disks, 0, -1):
            self.pegs_list[0].append(i)

    def create_widgets(self):
        self.canvas = Canvas(self, width=self.canvas_width, height=self.canvas_height, bg='white')
        self.canvas.pack(padx=10, pady=10)
        for i in range(self.pegs):
            self.draw_peg(i)
        self.draw_disks()
        self.move_button_frame = Frame(self)
        self.move_button_frame.pack(pady=(0, 10))
        for i in range(self.pegs):
            button = Button(self.move_button_frame, text=f'Move from {i+1}', command=lambda peg=i: self.select_peg(peg))
            button.pack(side='left', padx=10)
        self.moves_label = tk.Label(self, text=f"Moves: {self.moves}")
        self.moves_label.pack(pady=(10,0))

    def draw_peg(self, peg):
        x = (self.canvas_width / (self.pegs + 1)) * (peg + 1)
        self.canvas.create_rectangle(x - self.peg_width / 2, 0, x + self.peg_width / 2, self.canvas_height, fill='black')

    def draw_disks(self):
        self.canvas.delete("disk")  # Remove existing disks before redrawing
        for peg_index, peg in enumerate(self.pegs_list):
            for disk_index, disk in enumerate(peg):
                self.draw_disk(peg_index, disk_index, disk)

    def draw_disk(self, peg_index, disk_index, disk_size):
        x = (self.canvas_width / (self.pegs + 1)) * (peg_index + 1)
        y = self.canvas_height - (disk_index + 1) * self.disk_height
        self.canvas.create_rectangle(x - disk_size * 15, y, x + disk_size * 15, y + self.disk_height, fill='blue', tags="disk")

    def select_peg(self, peg):
        if self.selected_disk is None and self.pegs_list[peg]:
            self.selected_disk = (peg, self.pegs_list[peg].pop())
        else:
            if self.selected_disk and (peg != self.selected_disk[0]) and (not self.pegs_list[peg] or self.selected_disk[1] < self.pegs_list[peg][-1]):
                self.pegs_list[peg].append(self.selected_disk[1])
                self.selected_disk = None
                self.moves += 1
                self.moves_label.config(text=f"Moves: {self.moves}")
                self.check_win()
            elif self.selected_disk:
                self.pegs_list[self.selected_disk[0]].append(self.selected_disk[1])
                self.selected_disk = None
        self.draw_disks()

    def check_win(self):
        # Check if the last peg contains all disks
        if len(self.pegs_list[-1]) == self.disks:
            tk.messagebox.showinfo("Congratulations!", f"You won the game in {self.moves} moves!")
            self.restart_game()

    def restart_game(self):
        self.destroy()
        game = TowerOfHanoi()
        game.mainloop()
if __name__ == "__main__":
    disks = simpledialog.askinteger("Input", "How many disks?", minvalue=1, maxvalue=10)
    pegs = simpledialog.askinteger("Input", "How many pegs?", minvalue=3, maxvalue=5)
    if disks and pegs:
        game = TowerOfHanoi(disks=disks, pegs=pegs)
        game.mainloop()
