#we can store data in json  so other programmers as well as programming lanjuages can use it
#2 functions are used json.dump() and json.load()
import json

numbers = [2,8,9,7,10]
file_name =("D:\\numbers.json")
with open(file_name,'r+') as func_obj:
    json.dump(numbers,func_obj)

    func_obj.seek(0)          #places cursor at behind info so we can load it


#second this could be on anyother .py file
import json

filename = "D:\\numbers.json"

with open(filename, 'r') as f:
    numbers = json.load(f)             #here it can show error because after dumping cursor goes to end of data
                                        #and there is nothing after so use func_obj.seek(0)

print(numbers)


