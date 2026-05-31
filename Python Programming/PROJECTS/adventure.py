print ("welcome to fantasy characer creator ")
print (''' CHOOSE YOUR CLASS
             1.EVIL GENIUS
             2.LUFFY
             3.LELOUCH 
             (give no alone)''')
m=int(input(" enter your choice "))
dict = {
    1: "GUN ,WEAPONS + NERD LOOK",
    2: "DUMB",
    3:"AURA FARM"
}
print (dict.get(m,"enter only mentioned integers"))

# more important step understand this

characters = [("Iron Man", "Genius billionaire"), ("Thor", "God of Thunder")]
for i, (name, desc) in enumerate(characters, start=1):
    print(f"{i}. {name} - {desc}")