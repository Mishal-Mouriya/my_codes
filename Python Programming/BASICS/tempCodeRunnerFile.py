
}

cmd=0
while(cmd!=2):

    cmd=int(input("enter 2 to exit>"))
    no=input("enter your phone no >")
   
  

    for digit in no:
        print( f"{mood_dict.get(int(digit))} |")
        print('\n')