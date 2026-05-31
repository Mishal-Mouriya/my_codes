#                revised on 31/5/25
#this is  a guess game u have 3 trials lets start

i=0
while i<3:
    guess = int(input("enter your guess: "))
    if guess == 9 :
        print("u won u have chi")
        i=10
    else:
        print("try again")
        i = i+1
if guess != 9 :
    print("u used up all of ur chances lol")
print ("the end")



