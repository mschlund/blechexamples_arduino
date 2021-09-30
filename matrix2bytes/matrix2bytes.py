import tkinter as tk

ACTIVE = "red"
INACTIVE = "black"

def toggle(event):
  button=event.widget
  color=button["bg"]
  if(color==INACTIVE):
    color_to_set = ACTIVE
  else:
    color_to_set = INACTIVE
  button["bg"] = color_to_set
  get_state()

def button_to_str(btn):
  return "1" if (btn["bg"]==ACTIVE) else "0"

def reset():
  for row in range(0,8):
    for col in range(0,8):
      buttons[row][col]["bg"] = INACTIVE
  get_state()

def get_state():
  # iterate over all the buttons and get state from "bg",
  # write states of each column as an 8 byte array (in hex)
  cols_as_bytes = [ hex(int("".join([button_to_str(buttons[row][col]) for row in range(0,8)]
                        ), 2)) for col in range(0,8)]
  rows_as_bytes = [hex(int("".join([button_to_str(buttons[row][col]) for col in range(0,8)]
                        ), 2)) for row in range(0,8)]
  bytes_as_cstring = "{" + ", ".join(rows_as_bytes) + "}"
  ent_state.delete(0, tk.END)
  ent_state.insert(0, str(bytes_as_cstring))

window = tk.Tk()

frame = tk.Frame(master=window)
frame.pack()
buttons = [
            [tk.Button(master=frame, bg=INACTIVE, text=" ") for _ in range(0,8)]
            for _ in range(0,8)
          ]

for row in range(0,8):
  for col in range(0,8):
    buttons[row][col].grid(row=row, column=col)
    buttons[row][col].bind("<Button-1>", toggle)

ent_state = tk.Entry(master=window, width=60)
ent_state.pack()

btn_reset = tk.Button(master=window, text="Reset", command=reset)
btn_reset.pack()

window.mainloop()