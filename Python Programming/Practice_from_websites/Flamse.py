#20/5/26
#ok lets do the flames program one more time
name1=input("enter person 1 name\n")
name1=name1.lower().rstrip().replace(" ","")

name2=input("enter person 2 name\n")
name2=name2.lower().replace(" ","")

#now deleting
for x in name1[:]:
    if x in name2:
        name1=name1.replace(x,"",1)    #mistake1=you should update name1 not just put   name1.replace(x,"",1)      
        name2=name2.replace(x,"",1)  #concept->deleting terms in your string

cancelno=len(name1+name2)
flames = ["Friends", "Lovers", "Affectionate", "Marriage", "Enemies", "Siblings"]

#now how to cancel by iterating over list?

while(len(flames)>1):
    #first index is subracted minus 1 because index starts from zero
    index=(cancelno%len(flames))-1

    #now spliting(removing element) and rotating(to start after deleted index)
    if index>=0:
        left=flames[:index]
        right=flames[index+1:]
        flames=right+left
    else:#only possible negative values is minus one which is last element
        flames=flames[:len(flames)-1]#remove it



#printing result
print("Your relationship status is ",flames[0])