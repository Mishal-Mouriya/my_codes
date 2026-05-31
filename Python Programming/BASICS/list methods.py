  #revised on 31/5/25
list=[2,4,5,7,8,2,3,7]
#we will see different list methods here
print(list.count(2))
print(list.index(2))
print(list.remove(3))
print(list.pop(2))
print(list.clear())
print (50 in list)
list.reverse()
list.sort()
list.insert(1,'a')

#removing repeating elements in a list
list=[2,4,5,6,6,6,8,2,2,9]
for i in list:
    if list.count(i)>1:
        list.remove(i)
    else:
        continue
print(list)