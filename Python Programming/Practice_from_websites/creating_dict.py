
# creating a dictionary using class 

#1mistake,1concept,1optimization

class Page:

    def __init__(self, word, mean):
        self.word = word
        self.mean = mean
                                                       #mistake1->keeping function name
                                                       #and attribute name same
    def show_word(self):
        print(f"The word is: {self.word}")

    def show_meaning(self):
        print(f"The meaning is -> {self.mean}")


dictionary = []
i = 0

while True:

    word = input("Enter your word > ")
    meani = input("Enter its meaning > ")

    dictionary.append(Page(word, meani))   #concept-->YOU can put objects into lists!!!!
    i += 1

    option = int(input("Click 0 to quit, click 1 to view dictionary > "))

    if option == 0:
        break

    if option == 1:

        for x in range(i):           #optimization1-->this could be more neatly written as for page in dictionary[]directly

            print(f"\nPage {x+1}")

            dictionary[x].show_word()
            dictionary[x].show_meaning()

            print("\n")
