# 12/6/25

import random
while True :
    bot_choice = random.choice(["rock", "paper", "scissors"])
    user_choice = input("Enter your choice: ").lower().replace(" ", "")
    valid_choices = ["rock", "paper", "scissors"]
    if user_choice not in valid_choices:
        print("Invalid choice! Please choose rock, paper, or scissors.")
        continue

    if bot_choice == "rock":
        print(f"computer chose {bot_choice}")
        print(f"your choice is {user_choice}")
        if user_choice == "scissors":
            print("You lose!")
        if user_choice == "paper":
            print("You win!")
        if user_choice == "rock":
            print ("tie")

    elif bot_choice == "paper":
        print(f"computer chose {bot_choice}")
        print(f"your choice is {user_choice}")
        if user_choice == "scissors":
            print("You win!")
        if user_choice == "paper":
            print("tie!")
        if user_choice == "rock":
            print("lose")

    elif bot_choice == "scissors":
        print(f"computer chose {bot_choice}")
        print(f"your choice is {user_choice}")
        if user_choice == "scissors":
            print("tie!")
        if user_choice == "paper":
            print("You lose!")
        if user_choice == "rock":
            print("win")

    else:
        print("invalid choice")
    print('do you want to play again? (y/n)')
    again = input()
    if again == "y":
        pass
    else:
        break