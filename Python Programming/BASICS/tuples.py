#Tuples are immmutable so the only function u can do with them is to get info from them using count and index
tuple=(1,4,5,6,4,2)
#now we are going to use a stong method called unpacking
#x,y,z=tuple
#print(x,y,z)
#this will give error so without getting error we have 3 options

#Option 1: Only unpack 3 elements (if you only need the first three):
x, y, z = tuple[:3]
print(x, y, z)


#Option 2: Use the * operator to collect the remaining values:
# If you want to keep the first value in x, the second in y, and everything else in z:
x, y, *z = tuple
print(x, y, z)  # z will be a list: [5, 6, 4, 2]


#Option 3: Match all 6 elements:
a, b, c, d, e, f = tuple
print(a, b, c, d, e, f)