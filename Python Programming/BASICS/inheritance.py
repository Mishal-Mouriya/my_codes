# 🧓 PARENT CLASS: Person
# This class defines general human characteristics.
class Person:
    def __init__(self, age, name, gender):
        # 🧠 Attributes common to all persons
        self.age = age
        self.name = name
        self.gender = gender

    def talk(self):
        # 🎤 A method to introduce the person
        print(f"Hello, I am {self.name}. My age is {self.age}.")

    def salary(self, salary):
        # 💰 A method to set and show salary
        self.salary = salary
        print(f"{self.name}'s salary is {self.salary}")


# 🔬 OBJECT OF PARENT CLASS
person1 = Person(age=20, name="John", gender="M")
person1.salary(100)   # Calling salary method
person1.talk()        # Calling talk method


print("\n🔽 CHILD CLASS CODE BEGINS HERE 🔽\n")


# 🤖 CHILD CLASS: Ai
# This class inherits from Person and adds IQ-related features.
class Ai(Person):
    def __init__(self, age, name, gender):
        # 🧬 Inherit all Person properties using super()
        super().__init__(age, name, gender)  # simply doing the job of lines 9,10,11

        # 🧠 Additional attribute specific to AI
        self.iq1 = 100  # Default IQ value

    def iq(self, iq):
        # ⚙️ A method to update and print the AI's IQ
        self.iq1 = iq
        print(f"{self.name}'s IQ is {self.iq1}")

    # 🔄 Overriding the talk method
    def talk(self):
        super().talk()  # Call the original talk() from Person
        print(f"I am an AI with an IQ of {self.iq1}.")


# 🔧 OBJECTS OF CHILD CLASS
jarvis = Ai(name="Jarvis", age=2, gender="AI")

jarvis.iq(100)       # Call the method to set and show IQ
jarvis.salary(100)   # Inherited method from Person
jarvis.talk()        # Overridden method from Ai


# Creating another AI object to show multiple instances
sophia = Ai(age=5, name="Sophia", gender="AI")

sophia.talk()        # Calls overridden talk method, shows IQ info
sophia.iq(150)       # Sets and prints IQ

# Accessing parent and child attributes separately
print(f"{sophia.name} is {sophia.age} years old and has IQ {sophia.iq1}.")
