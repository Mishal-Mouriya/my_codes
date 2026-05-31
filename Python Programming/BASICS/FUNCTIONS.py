                                               # 31/5/25
# parameters are place holders that we define to send info to functions
# arguments are the actual pieces of information
               #                                 *(((({{{{******PROJECT GREETINGS******))))}}}

def birthday_func(name,age):
    print(f"Happy {age}th Birthday 😍😍😍,{name}")
def wedding_func(name1,name2,year):
    print(f"Happy {year}th Wedding Anniversary,{name1} and {name2}")

greet_dictionary = {
    "birthday": birthday_func,
    "wedding": wedding_func,
}

def greet_func(greet,**kwargs):
        func = greet_dictionary.get(greet)
        func(**kwargs)

print('''WELCOME TO GREETING PROJECT CHOOSE ONE
                2.Wedding 
                1.Birthday''')
choice= int(input("enter u choice as 1 or 2"))

if choice == 1:
    greet=("birthday")
    name=input("enter your name")
    age=int(input("enter your age"))
    greet_func(greet,name=name,age=age)

elif choice == 2:
    greet=("wedding")
    name1=input("enter  brides name")
    name2=input("enter  grooms name")
    year =int(input("enter years "))
    greet_func(greet,name1=name1,name2=name2,year=year)
else:
    print("enter u choice as 1 or 2 only")



