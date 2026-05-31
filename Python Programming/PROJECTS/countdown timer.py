# countdown timer program done on 12/6/25
import time  # Importing time module to use sleep for delaying output

user_time = int(input("Please enter countdown duration in seconds: "))  # Get countdown duration from user

def countdown(user_time):  # Define the countdown function
    while user_time > 0:  # Loop until the timer hits 0
        mins, secs = divmod(user_time, 60)               # Convert total seconds to minutes and seconds
        timer = f"{mins:02d}:{secs:02d}"                 # Format the time as MM:SS using f-string
        print(f"\r{timer}  ", end="")                    # Print timer at line start & overwrite previous text
        time.sleep(1)                                    # Wait for 1 second
        user_time -= 1                                   # Decrease the time by 1 second

    print("\nBOOM 💥 I am a mad scientist")  # Final message when countdown finishes

countdown(user_time)  # Call the countdown function with user's input
