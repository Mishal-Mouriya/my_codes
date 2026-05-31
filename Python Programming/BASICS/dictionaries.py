

          #revised on 31/5/25
        #                                      [[[[[[[[[[ 30/5/25 ]]]]]]]]]

                                               #revised on 31/5/25

                                             #we are learning about dictionary topic now cool isnt it heres one program
mood_dict = {
    0: "😴 chill",
    1: "🔥 fired up",
    2: "😂 giggling",
    3: "🤔 thinking",
    4: "💪 strong",
    5: "😎 cool",
    6: "😵 dizzy",
    7: "🥳 partying",
    8: "👽 alien mode naanga normal people kedaiyuthu",
    9: "🧠 genius"
}

str_input = input("Enter your phone number (for a mood reading 🧙‍♂️): ")
output = ""

for ch in str_input:                                                     # this is the key part ✌️
    digit = int(ch)
    output += mood_dict.get(digit, "❓ unknown vibe") + " | "

print("\nYour phone number's mood vibe is:\n")
print(output)


#this is my second project