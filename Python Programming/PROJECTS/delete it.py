#now i am going to revise classes lets go
class Student:
    def __init__ (self,name,score,rank="undefined"):
        self.name=name
        self.score=score
        self.rank=rank
    def run(self):
        print("the student is running away")
    def show_rank (self):
        print (f"the student hesitantle shows his rank: {self.rank}")
    def enquiry(self):
        print (f"the student replies his name is {self.name}")

pranav1 = Student (name="pranav",score=500,rank="1118")
pranav1.enquiry()
pranav1.show_rank()

sreesha = Student("sreshaha",500)
sreesha.enquiry()
sreesha.show_rank()

class College_student(Student):
    def __init__(self,name,score,rank="undefined",branch=""):
        super().__init__(name,score,rank)
        self.branch = branch
    def drive(selfself):
        print("this student can drive")
    def girlfriend(selfs):
        print("this student has a girlfriend")

praneesh= College_student("praneesh",500,3000,"computer")
praneesh.drive()
praneesh.girlfriend()
praneesh.enquiry()

#


