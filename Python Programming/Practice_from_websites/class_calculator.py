#Exercise 2: Develop a class Calculator with methods to add and subtract two numbers.
#revised very simple


class Calculator:

    def __init__(self,a,b):
        self.a=a
        self.b=b
    
    def add(self):
        return self.a + self.b
    
    def subract(self):
        return self.a-self.b
    
    def multiply(self):
        return self.a*self.b


casio = Calculator(25,67)

print("sum is ",casio.add())
print("\ndifference is ",casio.subract())








