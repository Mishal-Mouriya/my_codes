
mood_dict ={    
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

cmd=0
while(cmd!=2):

    cmd=int(input("enter 2 to exit>"))
    no=input("enter your phone no >")
   
  

    for digit in no:
        print( f"{mood_dict.get(int(digit))} |")
        print('\n')