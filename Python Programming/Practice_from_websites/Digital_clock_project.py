# 4 mistakes but many concepts learned

#importing necessary modules
import sys
import time
import sevseg


secondsleft = int(input("Enter timer value: "))
print("Use Ctrl+C to stop")


def split_time(seconds):

    hrs = seconds // 3600
    mins = (seconds % 3600) // 60
    sec = seconds % 60

    return hrs, mins, sec


def displaytimer(hrs, mins, sec):

    # Generate seven-segment strings
    h_digits = sevseg.getSevSegStr(hrs, 2)
    m_digits = sevseg.getSevSegStr(mins, 2)
    s_digits = sevseg.getSevSegStr(sec, 2)

    # Split them into rows
    h_top, h_mid, h_bot = h_digits.splitlines()
    m_top, m_mid, m_bot = m_digits.splitlines()  #mistake 1 used split( instead of split_lines_()
    s_top, s_mid, s_bot = s_digits.splitlines()

    # Display timer
    print(h_top + "     " + m_top + "     " + s_top)
    print(h_mid + "  •  " + m_mid + "  •  " + s_mid)
    print(h_bot + "  •  " + m_bot + "  •  " + s_bot)


try:

    while secondsleft >= 0:

        print("\n" * 40)

        # Convert into hrs/min/sec
        hrs, mins, sec = split_time(secondsleft)

        print("________________ COUNTDOWN TIMER ________________\n")

        # Display timer
        displaytimer(hrs, mins, sec)  #varible name mismatch

        # End condition
        if secondsleft == 0:
            print("\n💥 BOOM OVER 💥")  #mistake 2 forgot to add break
            break

        # Delay
        time.sleep(1)

        # Update value
        secondsleft -= 1


except KeyboardInterrupt: #mistake 4->left except bland without giveing keyboard interrupt which means it will cathc all errors whic is bad

    print("\nCountdown stopped.")
    sys.exit()