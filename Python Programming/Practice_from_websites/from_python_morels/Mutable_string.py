#Many new concepts.. so much huh

class MutableString:
    
    # Runs automatically when an object is created
    # Example:
    # greeting = MutableString("Hello")
    def __init__(self, text=""):
        
        # Convert the string into a list of characters
        # "Hello" -> ['H', 'e', 'l', 'l', 'o']
        # We do this because lists are mutable
        self.characters = list(text)



    # Controls what print(obj) displays
    # Example:
    # print(greeting)
    def __str__(self):
        
        # Convert the character list back into a string
        return "".join(self.characters)



    # Controls what appears in the Python interpreter
    # Example:
    # >>> greeting
    # 'Hello'
    def __repr__(self):
        
        # repr() adds quotes around strings
        return repr(str(self))



    # Controls len(obj)
    # Example:
    # len(greeting)
    def __len__(self):
        
        # Return the length of the character list
        return len(self.characters)



    # Controls obj[index]
    # Example:
    # greeting[1]
    def __getitem__(self, index):
        
        # Return the character at the given index
        return self.characters[index]



    # Controls obj[index] = value
    # Example:
    # greeting[1] = "a"
    def __setitem__(self, index, value):
        
        # Replace the character at the given index
        self.characters[index] = value



    # Controls "something" in obj
    # Example:
    # "ell" in greeting
    def __contains__(self, item):
        
        # Convert object to string and perform normal string search
        return item in str(self)



    # Controls obj + other
    # Example:
    # greeting + "!"
    def __add__(self, other):
        
        # Concatenate as normal strings
        return str(self) + str(other)



    # Called when Python cannot find an attribute or method
    # Example:
    # greeting.upper()
    # greeting.lower()
    # greeting.endswith("!")
    def __getattr__(self, name):
        
        # Get the same method from the equivalent string
        return getattr(str(self), name)