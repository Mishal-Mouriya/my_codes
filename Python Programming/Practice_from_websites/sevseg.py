#this is a module
# sevseg.py
# Simple seven-segment display module

DIGITS = {
    "0": [" __ ",
          "|  |",
          "|__|"],

    "1": ["    ",
          "   |",
          "   |"],

    "2": [" __ ",
          " __|",
          "|__ "],

    "3": [" __ ",
          " __|",
          " __|"],

    "4": ["    ",
          "|__|",
          "   |"],

    "5": [" __ ",
          "|__ ",
          " __|"],

    "6": [" __ ",
          "|__ ",
          "|__|"],

    "7": [" __ ",
          "   |",
          "   |"],

    "8": [" __ ",
          "|__|",
          "|__|"],

    "9": [" __ ",
          "|__|",
          " __|"]
}


def getSevSegStr(number, minWidth=0):
    """
    Converts a number into seven-segment display text.

    Parameters:
        number -> number/string to display
        minWidth -> minimum digit width
    """

    # Convert integer to string
    number = str(number)

    # Add leading zeros if needed
    number = number.zfill(minWidth)

    # Stores the 3 display rows
    rows = ["", "", ""]

    # Build each row
    for digit in number:

        # Ignore unsupported characters
        if digit not in DIGITS:
            continue

        pattern = DIGITS[digit]

        for i in range(3):
            rows[i] += pattern[i] + " "

    # Return combined multi-line string
    return "\n".join(rows)


# Test section
if __name__ == "__main__":
    print(getSevSegStr(12, 2))
