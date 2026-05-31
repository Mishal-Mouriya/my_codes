import random

class RandomWalk:
    """A class to generate random walks on a 2D plane."""

    def __init__(self, num_of_points=6000):
        """Initialize attributes for the walk."""
        self.num_of_points = num_of_points

        # Start the walk at the origin (0, 0)
        self.x_values = [0]
        self.y_values = [0]

    def fill_walk(self):
        """Generate all the points for the walk."""

        # Keep walking until we have the desired number of points
        while len(self.x_values) < self.num_of_points: 
            
            # Choose direction and distance for x
            x_direction = random.choice([1, -1])
            x_distance = random.choice([0, 1, 2, 3, 4, 5])
            x_step = x_direction * x_distance

            # Choose direction and distance for y
            y_direction = random.choice([1, -1])
            y_distance = random.choice([0, 1, 2, 3, 4, 5])
            y_step = y_direction * y_distance

            # Reject steps that go nowhere (no movement)
            if x_step == 0 and y_step == 0:
                continue

            # Calculate the next position
            next_x = self.x_values[-1] + x_step
            next_y = self.y_values[-1] + y_step

            # Append new position to the walk
            self.x_values.append(next_x)
            self.y_values.append(next_y)

''' hereby class randomwalk is done since this is big we will leave it here and import and use this stuff'''

        

