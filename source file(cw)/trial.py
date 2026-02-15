import customtkinter as ctk
from tkcalendar import DateEntry
import json
import os

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

FILE = "data.json"

# ---------------- STORAGE ----------------
def load_tasks():
    if os.path.exists(FILE):
        with open(FILE, "r") as f:
            return json.load(f)
    return []

def save_tasks():
    with open(FILE, "w") as f:
        json.dump(tasks, f, indent=4)

tasks = load_tasks()

# ---------------- CLASSIFICATION ----------------
def classify(task):
    if task["important"] and task["urgent"]:
        return "Do Now"
    elif task["important"] and not task["urgent"]:
        return "Schedule"
    elif not task["important"] and task["urgent"]:
        return "Delegate"
    else:
        return "Eliminate"

# ---------------- GUI ----------------
app = ctk.CTk()
app.title("Task Commander")
app.geometry("1000x650")

# -------- LEFT PANEL (Add Task) --------
left_frame = ctk.CTkFrame(app)
left_frame.pack(side="left", fill="y", padx=10, pady=10)

ctk.CTkLabel(left_frame, text="Add Task", font=("Arial", 20)).pack(pady=10)

title_entry = ctk.CTkEntry(left_frame, placeholder_text="Task Title")
title_entry.pack(pady=5)

desc_entry = ctk.CTkEntry(left_frame, placeholder_text="Description")
desc_entry.pack(pady=5)

date_picker = DateEntry(left_frame)
date_picker.pack(pady=5)

important_var = ctk.BooleanVar()
urgent_var = ctk.BooleanVar()

ctk.CTkCheckBox(left_frame, text="Important", variable=important_var).pack()
ctk.CTkCheckBox(left_frame, text="Urgent", variable=urgent_var).pack()

def add_task():
    task = {
        "title": title_entry.get(),
        "desc": desc_entry.get(),
        "date": date_picker.get(),
        "important": important_var.get(),
        "urgent": urgent_var.get()
    }
    tasks.append(task)
    save_tasks()
    refresh_matrix()

ctk.CTkButton(left_frame, text="Add Task", command=add_task).pack(pady=10)

# -------- RIGHT PANEL (Matrix + Calendar) --------
right_frame = ctk.CTkFrame(app)
right_frame.pack(side="right", fill="both", expand=True, padx=10, pady=10)

matrix_frame = ctk.CTkFrame(right_frame)
matrix_frame.pack(fill="both", expand=True)

labels = {}

quadrants = ["Do Now", "Schedule", "Delegate", "Eliminate"]

for i, quad in enumerate(quadrants):
    frame = ctk.CTkFrame(matrix_frame, width=200, height=200)
    frame.grid(row=i//2, column=i%2, padx=10, pady=10, sticky="nsew")
    ctk.CTkLabel(frame, text=quad, font=("Arial", 16)).pack()
    labels[quad] = ctk.CTkTextbox(frame, width=250, height=200)
    labels[quad].pack()

matrix_frame.grid_rowconfigure((0,1), weight=1)
matrix_frame.grid_columnconfigure((0,1), weight=1)

# -------- Refresh Matrix --------
def refresh_matrix():
    for quad in labels:
        labels[quad].delete("1.0", "end")

    for task in tasks:
        quad = classify(task)
        labels[quad].insert("end", f"{task['title']} ({task['date']})\n")

refresh_matrix()

app.mainloop()
