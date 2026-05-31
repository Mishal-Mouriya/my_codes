#revise
# TOTAL MISTAKES FIXED: 4
# TOTAL OPTIMIZATIONS ADDED: 5


import json
from pathlib import Path

path = Path(r"C:\Users\SRI\vs code programs\Python Programming\Practice_from_websites\passwords.txt")

# Optimization 1: Ensure the file exists before we try to read/write it. 
# If the file doesn't exist, reading it later will cause a FileNotFoundError.
if not path.exists():
    with open(path, "w") as f:
        json.dump({}, f)

def add(ac_name, pwd):
    # Optimization 2: Read the existing file data first. If we don't do this, 
    # writing new data will overwrite and erase all previously saved passwords.
    with open(path, "r") as f:
        data = json.load(f) 
        
    data[ac_name] = pwd
    
    # Mistake 1: json.dumps() converts a dictionary to a string, it doesn't write to a file.
    # Mistake 2: You cannot pass a path directly into json.dump(). You must open the file first.
    # Fix: Open the file in "w" (write) mode and use json.dump(data, file).
    with open(path, "w") as f:
        json.dump(data, f, indent=4) 


def view(ac_name):
    # Mistake 3: json.loads() parses a JSON string, not a file path. 
    # Fix: We must open the file in "r" (read) mode and use json.load(file).
    with open(path, "r") as f:
        data = json.load(f)
        
    # Optimization 3: Use an if/else check before printing. 
    # If the user types an account name that doesn't exist, data[ac_name] will cause a KeyError crash.
    if ac_name in data:
        print(f"Password: {data[ac_name]}")
    else:
        print(f"No account found for '{ac_name}'.")


pwd = input("Enter Master Password: ")
if pwd == "mu":
    print("1. Add\n2. View\n3. Quit\n")

    while True:
        # Optimization 4: Added .strip() to remove any accidental spaces 
        # the user might type before or after their choice.
        choice = input("Enter your choice> ").strip()

        if choice.lower() == 'add':
            ac_name = input("account name> ")
            passwo = input("password> ")
            add(ac_name, passwo)

        elif choice.lower() == 'quit':
            break
        
        # Mistake 4: Changed 'view()' to 'view'. 
        # Checking for 'view()' forced the user to literally type the parentheses to trigger this block.
        elif choice.lower() == 'view':
            ac_name = input("enter ac_name> ")
            view(ac_name)
        
        # Optimization 5: Added an else block. 
        # If the user types a wrong menu option, this tells them instead of failing silently.
        else:
            print("Invalid choice. Please type 'add', 'view', or 'quit'.")
else:
    print("Incorrect Master Password. Access Denied.")