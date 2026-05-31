# 1. Define a function that accepts **kwargs

def print_user_profile(**kwargs):
    # Inside the function, kwargs is a normal dictionary
    for key, value in kwargs.items():                       #to get both key and value items function used
        print(f"{key}: {value}")

# 2. Create a standard dictionary
my_dictionary = {
    "name": "Alex",
    "role": "Developer",
    "language": "Python"
}

# 3. Pass the dictionary into the function using **
print_user_profile(**my_dictionary) #it unpacks and sends in and kwargs packs it again..

#u can keep function as function(name,role,langauge) and ** dictionary will provide arguments by
#unpacking..only thing is that it should have the exact keys..