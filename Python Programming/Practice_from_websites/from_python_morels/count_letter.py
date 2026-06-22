#This is the problem from pyton morsels 
#new concpts learned


import json

sentence = input("enter  your sentence>")
senlist=sentence.split(" ")
wordtuple=tuple(senlist)   #concept 1  #actually no need for tuple just showing conversion is plausible
 
#now creating a library for key value combo
library={}


for word1 in wordtuple:
    count=0
    for word2 in wordtuple:
        if(word1 == word2):
            count=count+1

    library[word1]=count

string=json.dumps(library,indent=4)           #concept 2
print(string)

    