#17/6/25 1 hour spent
# 📘 Today we are going to learn about File Handling in Python (from the book)

path = "D:\\heavens feel\\PYTHON RESOURCES\\3rd edition resources\\pcc_3e-main\\chapter_10\\partial_programs\\reading_from_a_file\\pi_digits.txt"           # 🗂️ File path to pi_digits
path2 = "D:\\heavens feel\\PYTHON RESOURCES\\3rd edition resources\\pcc_3e-main\\chapter_10\\partial_programs\\reading_from_a_file\\pi_million_digits.txt"  # 🗂️ File path to pi_million_digits


# 🔹 Part 1: OPENING AND READING CONTENT

with open(path, encoding="utf-8") as file_object:                # 📂 Open file with UTF-8 encoding
    string = file_object.read()                                  # 🧾 Read file content as one string
    print(string, "\n\n")                                        # 📤 Print the content

with open(path, encoding="utf-8") as file_object:                # 📂 Re-open file to read lines
    line_list = file_object.readlines()                          # 📃 Read lines into a list
    print(line_list, "\n\n")                                     # 📤 Print the list of lines

# 📝 Note: You can also loop with "for line in file_object", but using functions here gives better control.
# 🧠 Also, splitlines() works similarly for strings.


# 🎯 Part 2: Birthday Search in 1 Million Digits of Pi

with open(path2, encoding="utf-8") as file_object:               # 📂 Open large Pi file
    lines = file_object.readlines()                              # 📄 Read all lines into a list
    pi_string = ""                                               # 🔤 Initialize empty string

    for line in lines:                                           # 🔁 Loop through each line
        pi_string += line.strip()                                # 🧹 Strip newline & spaces

    birth_date = input("📅 Enter your birth date : ")            # 📥 User input (e.g. 010199)
    if birth_date in pi_string:
        print("🎉 YES! Your birthday appears in the first million digits of Pi!")   # 🥳 Found!
    else:
        print("😢 Aww... your birthday isn't in the Pi string.")                    # 😓 Not found

# ⚠️ encoding="utf-8" is very important to avoid errors when dealing with special characters.


# 🛠️ Part 3: WRITING TO A FILE

path3 = "D:\\heavens feel\\PYTHON RESOURCES\\3rd edition resources\\pcc_3e-main\\chapter_10\\HAHA.txt"   # 📄 File to write into

with open(path3, 'r+', encoding="utf-8") as file_object3:           # 📂 Open file in read+write mode
    file_object3.write("super da maplai laugh until u die")         # ✍️ Write text to the file


# ✨ File modes in Python:
# 'r'   → Read
# 'w'   → Write (overwrites existing content)
# 'a'   → Append
# 'r+'  → Read and Write
