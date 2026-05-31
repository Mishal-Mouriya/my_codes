#12/6/25
#this is the code cleaned and improved by cbatgpt
import random

while True:
    bot_choice = random.choice(["rock", "paper", "scissors"])
    user_choice = input("Enter your choice (rock/paper/scissors): ").lower().replace(" ", "")

    if user_choice not in ["rock", "paper", "scissors"]:
        print("Invalid choice! Please try again.")
        continue

    print(f"Computer chose: {bot_choice}")
    print(f"You chose: {user_choice}")

    if user_choice == bot_choice:
        print("It's a tie!")
    elif (user_choice == "rock" and bot_choice == "scissors") or \
            (user_choice == "paper" and bot_choice == "rock") or \
            (user_choice == "scissors" and bot_choice == "paper"):
        print("You win!")
    else:
        print("You lose!")

    again = input("Do you want to play again? (y/n): ").lower()
    if again != "y":
        break
