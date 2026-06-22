# Employee hierarchy problem using inheritance

class Employee:

    def __init__(self, name, id, b_sal=None): #none makes argument optional very important

        self.name = name
        self.id = id
        self.b_sal = b_sal

    def calculate_pay(self):
        print(f"The pay is {self.b_sal}")


# Fulltime employee
class Fulltime(Employee):

    def __init__(self, name, id, b_sal):

        super().__init__(name, id, b_sal)

        self.bonus = 0.1 * b_sal               #optimization->no need to add seperately 

    # overriding parent method
    def calculate_pay(self):                    #mistake 1 forgot to add self

        total = self.b_sal + self.bonus

        print(f"The pay is {total}")

    def bonus1(self):

        print(f"Bonus is {self.bonus}")


# Part time employee
class Part_time(Employee):

    def __init__(self, name, id, hour_rate, hour_work):

        super().__init__(name, id)

        self.hour_rate = hour_rate
        self.hour_work = hour_work

    def calculate_pay(self):

        pay = self.hour_rate * self.hour_work

        print(f"The pay is {pay}")