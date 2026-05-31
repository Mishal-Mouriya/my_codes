            #this folfer is importable and explains usage of __name__ magic function



def factorial(n):
    """
    Returns factorial of a number n (recursive).
    """
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def formatted_name(first_name, last_name):
    return f"{first_name} {last_name}"


#this function has the test run
class Anonymous_survey :
    def __init__(self,question):
        self.question = question
        self.responses = []

    def show_question(self):
        print(self.question)

    def store_responses(self,*args):
        for x in args :                       #in order to get multiple responses
            self.responses.append(x)

    def show_responses(self):
        for x in self.responses:
            print(f" -{x}")






if __name__ == "__main__":
    """
    This block runs only when the file is executed directly.

    When this file is imported as a module in another script,
    the code inside this block does NOT run.

    It's useful for running tests, examples, or demo code without
    affecting imports.
        """

    language_survey = Anonymous_survey("What are the languages u speak?")
    print("to quit press q")
    respond_list = []
    while True:
        language_survey.show_question()
        response = input("> ")
        if response == "q":
            break
        respond_list.append(response)

    language_survey.store_responses(respond_list)
    language_survey.show_responses()
