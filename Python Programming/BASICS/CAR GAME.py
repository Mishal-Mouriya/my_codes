started = False

while True:
    command = input("Enter your command: ffffffff").lower()

    if command == "help":
        print('''
start - to start the car
stop - to stop the car
quit - to exit the game
        ''')
    elif command == "start":
        if started:
            print("Car is already started!")
        else:
            started = True
            print("Car started... Ready to go!")
    elif command == "stop":
        if not started:
            print("Car is already stopped.")
        else:
            started = False
            print("Car stopped.")
    elif command == "quit":
        print("Quitting the game. Bye!")
        break
    else:
        print("Sorry, I don't understand that command.")
