from tkinter import *
from tkinter import ttk
from tkinter import font as tkFont


root = Tk()
root.title("Automated Logos")
helv36 = tkFont.Font(family='Helvetica', size=18, weight=tkFont.BOLD)
root.geometry("800x480")
root.attributes("-fullscreen",True)
root.configure(bg="DARK GRAY")
root.rowconfigure(0,weight=1)
root.columnconfigure(0, weight=1)
root.resizable(0,0)

frm = ttk.Frame(root, padding=10)
frm.grid()
#ttk.Label(frm, text="Hello World!").grid(column=0, row=0)

def gameMode():
    print("Beginning Game Code...")
def sensorMode():
    print("Testing Sensors...")
def motorMode():
    print("Testing Motors...")
def experimental():
    print("WARNING: Experimental mode...")
    root.destroy()
    root2 = Tk()
    #helv36 = tkFont.Font(family='Helvetica', size=25, weight=tkFont.BOLD)
    root2.geometry("800x480")
    root2.attributes("-fullscreen",True)
    root2.configure(bg="DARK GRAY")
    root2.rowconfigure(0,weight=1)
    root2.columnconfigure(0,weight=1)
    frm2 = ttk.Frame(root2, padding=10)
    #frm2.grid(row=0, column=0, sticky="NSEW")
    frm2.grid(sticky="NSEW")
    #make a fixed screen
    root2.resizable(0,0)
    Button(frm2, text="M1+", command=lambda: gameMode(),width=22, height=11,bd=5,bg="LIGHT GREEN", font=helv36).grid(column=0, row=0,sticky="NSEW")
    Button(frm2, text="M1-", command=lambda: gameMode(),width=22, height=11,bd=5,bg="LIGHT GREEN", font=helv36).grid(column=0, row=1,sticky="NSEW")
    Button(frm2, text="M2+", command=lambda: sensorMode(),width=22, height=11,bd=5,bg="LIGHT BLUE", font=helv36).grid(column=1, row=0,sticky="NSEW")
    Button(frm2, text="M2-", command=lambda: motorMode(),width=22, height=11,bd=5,bg = "YELLOW", font=helv36).grid(column=1, row=1,sticky="NSEW")
    Button(frm2, text="EXPERIMENTAL", command=lambda: experimental(),width=22, height=11,bd=5,bg = "PINK", font=helv36).grid(column=3, row=0,sticky="NSEW")
    Button(frm2, text="EXIT", command=root2.destroy,width=22, height=11,bd=5,bg = "GRAY",font=helv36).grid(column=3, row=1,sticky="NSEW")
    #Button(frm2, text="EXIT", command=root2.go_back(),width=27, height=11,bd=5,bg = "GRAY",font=helv36).grid(column=3, row=1,sticky="NSEW")
    root2.mainloop()
    #ttk.Label(frm, text="Hello World!").grid(column=0, row=0)
    
#Opening window page
Button(frm, text="GAME CODE", command=lambda: gameMode(),width=16, height=7,bd=5,bg="LIGHT GREEN",font=helv36).grid(column=0, row=0,sticky="NSEW")
Button(frm, text="SENSOR OUTPUT", command=lambda: sensorMode(),width=16, height=7,bd=5,bg="LIGHT BLUE",font=helv36).grid(column=1, row=0,sticky="NSEW")
Button(frm, text="TEST MOTORS", command=lambda: motorMode(),width=16, height=7,bd=5,bg = "YELLOW",font=helv36).grid(column=2, row=0,sticky="NSEW")
Button(frm, text="EXPERIMENTAL", command=lambda: experimental(),width=16, height=7,bd=5,bg = "PINK",font=helv36).grid(column=0, row=1,sticky="NSEW")
Button(frm, text="EXIT", command=root.destroy,width=16, height=7,bd=5,bg = "GRAY",font=helv36).grid(column=1, row=1,sticky="NSEW")

root.mainloop()
