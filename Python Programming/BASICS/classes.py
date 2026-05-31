# 7/6/25 we are going to explore classes ,objects, methods and attributes and also little of inheritance



class Person:
    def __init__(self,age,name,gender):
        self.age = age
        self.name = name                               #these are attributes  kinda like values assigned to a object i guess
        self.gender = gender

    def talk(self):                                    #these funcs within class are methods similar to string methods or list methods
        print(f"hello i am {self.name}\n"
              f"\n my age is {self.age}")
        
    def salary(self,salary):
        self.salary = salary
        return self.salary



object1 = Person(20,"Smith","M")      #object is an instance of class
print(object1.gender)
object1.talk()

#also a good important point..you can make passing of several arguments optional by doing this
class Employee:
    def __init__(self, name, id=None, department=None):
        self.name = name
        self.id = id
        self.department = department

#now it is opeitonal to pass id and department



try:
    object2= Person()                    # these are exceptions if u know what errors may come u can prevent the program from crashing
    print(object2.gender)
except TypeError:
    print("u didnt enter positional argument damnit\n")






