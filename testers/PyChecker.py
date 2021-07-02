# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    PyChecker.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 10:36:03 by telron            #+#    #+#              #
#    Updated: 2021/06/18 03:51:41 by copihendo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import *
import sys
import time
import signal

class Stacks:
    def __init__(self, argv, cmds):
        data = [[int(num), 0] for num in argv]
        for index, num in enumerate(sorted(data)):
            num[1] = index + 1
        self.stack_A = [index for _, index in data]
        self.stack_B = []
        self.history = []
        self.add_history()
        self.run(cmds)

    def add_history(self):
        self.history.append([self.stack_A.copy(), self.stack_B.copy()])

    def pb(self):
        if (len(self.stack_A)):
            self.stack_B = [self.stack_A[0]] + self.stack_B
            self.stack_A = self.stack_A[1:]
        self.add_history()

    def pa(self):
        if (len(self.stack_B)):
            self.stack_A = [self.stack_B[0]] + self.stack_A
            self.stack_B = self.stack_B[1:]
        self.add_history()

    def sa(self, can_add_history = 1):
        if (len(self.stack_A) >= 2):
            self.stack_A[0], self.stack_A[1] = self.stack_A[1], self.stack_A[0]
        if (can_add_history):
            self.add_history()

    def sb(self, can_add_history = 1):
        if (len(self.stack_B) >= 2):
            self.stack_B[0], self.stack_B[1] = self.stack_B[1], self.stack_B[0]
        if (can_add_history):
            self.add_history()

    def ss(self):
        self.sa(0)
        self.sb(0)
        self.add_history()

    def ra(self, can_add_history = 1):
        if (len(self.stack_A) >= 2):
            num = self.stack_A[0]
            self.stack_A = self.stack_A[1:] + [num]
        if (can_add_history):
            self.add_history()

    def rb(self, can_add_history = 1):
        if (len(self.stack_B) >= 2):
            num = self.stack_B[0]
            self.stack_B = self.stack_B[1:] + [num]
        if (can_add_history):
            self.add_history()

    def rr(self):
        self.ra(0)
        self.rb(0)
        self.add_history()

    def rra(self, can_add_history = 1):
        if (len(self.stack_A) >= 2):
            num = self.stack_A[-1]
            self.stack_A = [num] + self.stack_A[:-1]
        if (can_add_history):
            self.add_history()

    def rrb(self, can_add_history = 1):
        if (len(self.stack_B) >= 2):
            num = self.stack_B[-1]
            self.stack_B = [num] + self.stack_B[:-1]
        if (can_add_history):
            self.add_history()

    def rrr(self):
        self.rra(0)
        self.rrb(0)
        self.add_history()

    def run_cmd(self, str_cmd):
        cmds = (("pa", self.pa), ("pb", self.pb), ("sa", self.sa), ("sb", self.sb), \
            ("ss", self.ss), ("ra", self.ra), ("rb", self.rb), ("rr", self.rr), \
            ("rra", self.rra), ("rrb", self.rrb), ("rrr", self.rrr))
        for cmd in cmds:
            if (cmd[0] == str_cmd):
                cmd[1]()
                return

    def run(self, str_cmds):
        for str_cmd in str_cmds:
            self.run_cmd(str_cmd)


class PyChecker:
    def __init__(self, master):
        self.cmds = [line.rstrip("\n") for line in sys.stdin]
        self.stacks = Stacks(sys.argv[1:], self.cmds)

        self.count_number = len(sys.argv) - 1
        self.index_frame = 0
        self.width_canvas = 900
        self.height_canvas = 600
        self.pause_var = 1

        self.length_moves = len(self.cmds)
        self.master = master
        master.title("PyChecker")
        self.mainframe = Frame(master)
        self.mainframe.pack(fill=BOTH)
        self.upframe = Frame(self.mainframe, bg='gray')
        self.upframe.pack(side=TOP)
        self.can = Canvas(self.upframe, width=self.width_canvas, height=self.height_canvas, bg="black")
        self.can.pack(side=LEFT)
        self.listbox = Listbox(self.upframe, bg='black', fg='light cyan',
                               font=("monospace", 12), relief=FLAT, selectmode = SINGLE)
        self.listbox.pack(fill=BOTH, expand=1)
        self.listbox.bind("<<ListboxSelect>>", self.change_listbox)
        for cmd in ["start"] + self.cmds:
            self.listbox.insert(END, cmd)
        self.listbox.activate(0)
        self.Move = Label(self.upframe, text='move = 0')
        self.Move.pack()
        self.Count = Label(self.upframe, text='Count move = ' + str(self.length_moves))
        self.Count.pack()
        self.toolframe = Frame(self.mainframe)
        self.toolframe.pack(side=BOTTOM)
        self.Speed = Scale(self.toolframe, orient=HORIZONTAL, length=250, from_=1, to=self.length_moves // 10 + 1,  tickinterval=(self.length_moves // 10) / 4, resolution=1)
        self.Speed.set(self.length_moves // 20 + 1)
        self.Speed.pack(side=LEFT)
        self.ToStart = Button(self.toolframe, text="|<<", height=2, width=2, command=self.start_move)
        self.ToStart.pack(side=LEFT)
        self.Left = Button(self.toolframe, text="|<", height=2, width=2, command=self.previus_move)
        self.Left.pack(side=LEFT)
        self.Pause = Button(self.toolframe, text="||", height=2, width=2, command=self.pause)
        self.Pause.pack(side=LEFT)
        self.Play = Button(self.toolframe, text=">", height=2, width=2, command=self.play)
        self.Play.pack(side=LEFT)
        self.Right = Button(self.toolframe, text=">|", height=2, width=2, command=self.next_move)
        self.Right.pack(side=LEFT)
        self.ToFinish = Button(self.toolframe, text=">>|", height=2, width=2, command=self.finish_move)
        self.ToFinish.pack(side=LEFT)
        self.TimeLapse = Scale(self.toolframe, orient=HORIZONTAL, length=690, from_=0, to=self.length_moves, tickinterval=self.length_moves / 10, resolution=1, command=self.change_timelapse, repeatdelay=18)
        self.TimeLapse.pack(side=LEFT)
        self.show()

    def next_move(self):
        if (self.index_frame < self.length_moves):
            self.index_frame += 1
        self.show()

    def previus_move(self):
        if (self.index_frame >= 1):
            self.index_frame -= 1
        self.show()

    def start_move(self):
        self.index_frame = 0
        self.show()

    def finish_move(self):
        self.index_frame = self.length_moves
        self.show()

    def change_timelapse(self, value):
        self.index_frame = int(value)
        self.show()

    def change_listbox(self, _):
        self.index_frame = self.listbox.curselection()[0]
        self.show()

    def pause(self):
        self.pause_var = 1

    def play(self):
        self.pause_var = 0
        while (not self.pause_var and self.index_frame < self.length_moves + 1):
            count = (1 / 30) * self.Speed.get()
            self.index_frame += int(count)
            if (self.index_frame > self.length_moves):
                self.index_frame = self.length_moves
            self.show()
            delay = 1.0 / 30
            if (count < 1):
                delay /= count
            time.sleep(delay)
            self.index_frame += 1
        self.pause_var = 1

    def set_color(self, value):
        col = '#%02x%02x%02x' % (int(255 * (value - 0.3) * (value > 0.3)),
                                 int(255 * value - ((510 * (value - 0.6)) * (value > 0.6))),
                                 int((255 - 510 * value) * (value < 0.5)))
        return col

    def draw_number(self):
        if (self.count_number):
            moment = self.stacks.history[self.index_frame]
            height_block = self.height_canvas / self.count_number
            for index, number_A in enumerate(moment[0]):
                self.can.create_rectangle(0, index * height_block, \
                    10 + (number_A + 1) / self.count_number * (self.width_canvas / 2 - 100), (index + 1) * height_block, \
                    fill=self.set_color(number_A / self.count_number), outline="")
            for index, number_B in enumerate(moment[1]):
                self.can.create_rectangle(self.width_canvas / 2, index * height_block, \
                    self.width_canvas / 2 + 10 + (number_B + 1) / self.count_number * (self.width_canvas / 2 - 100), (index + 1) * height_block, \
                    fill=self.set_color(number_B / self.count_number), outline="")

    def show(self):
        self.can.delete("all")
        self.TimeLapse.set(self.index_frame)
        self.draw_number()
        self.listbox.activate(self.index_frame)
        self.listbox.see(self.index_frame)
        self.Move['text']= "Move " + str(self.index_frame)
        self.can.update()

root = Tk()
root.resizable(width=False, height=False)
gui = PyChecker(root)

def close(sig, frame):
    root.destroy()

def escape(_):
    root.destroy()

signal.signal(signal.SIGINT, close)
signal.signal(signal.SIGTSTP, close)
root.bind('<Escape>', escape)
root.mainloop()
