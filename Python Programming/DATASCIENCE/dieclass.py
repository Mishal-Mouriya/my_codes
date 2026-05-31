#we are going to create a die class 
from random import randint
class Die():
    def __init__(self,no_of_fases=6):
        self.no_of_fases = no_of_fases
    
    def roll_dice(self):
        return randint(1 , self.no_of_fases)
    
    