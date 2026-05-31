# Importing necessary modules


from rdm_walk import RandomWalk   # Custom class from your own file
from random import choice                 # To randomly pick directions
import matplotlib.pyplot as plt           # For plotting the walk

# Loop to keep asking the user if they want a new random walk
while True:
    command = input("Do you want one random walk? (y/n): ")

    if command.lower() == 'y':
        # Create a new random walk instance
        ant_moves = RandomWalk()
        ant_moves.fill_walk()

        # Create a plot
        fig, ax = plt.subplots()

        # Make a color gradient based on point order
        point_numbers = list(range(ant_moves.num_of_points))
        ax.scatter(ant_moves.x_values, ant_moves.y_values, c=point_numbers,
                   cmap=plt.cm.Blues, s=15)

        # Start and end points (highlight them)
        ax.scatter(0, 0, c='green', edgecolors='none', s=50)  # Start
        ax.scatter(ant_moves.x_values[-1], ant_moves.y_values[-1], 
                   c='pink'
                   ', edgecolors='none', s=50)          # End

        ax.set_aspect('equal')  # Keep aspect ratio square
        plt.show()

    elif command.lower() == 'n' or command.lower() == 'q':
        print("Okay, exiting the random walk simulation. 👋")
        break

    else:
        print("Please type 'y' to walk or 'q'' to quit.")


