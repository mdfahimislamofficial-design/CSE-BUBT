from tkinter import *
Window= Tk()
Window.title("CapScan")
Window.geometry("800x600")
    
def on_click():
    if label2.cget("text") == "日本語":
        label1.config(text="Language: ")
        label2.config(text="English")
        button.config(text="Japanese")
    else:
        label1.config(text="言語：")
        label2.config(text="日本語")
        button.config(text="English")

label1 = Label(Window, text="Language: ", font=("New Time", 16))
label1.grid(column=1,row=2)

label2 = Label(Window, text="English", font=("New Time", 16))
label2.grid(column=2,row=2)

button =Button(Window, text="Japanese", command=on_click)
button.grid(column=3,row=2)

Window.mainloop()