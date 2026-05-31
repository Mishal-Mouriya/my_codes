#revised on 31/5/25
#this is edited version using chatgpt i missed out fundamental
print("Give 3 numbers to find the greatest")
x = int(input())
y = int(input())
z = int(input())

nums = [x, y, z]

for no1 in nums:
    greatest = True  # Assume it's the greatest
    for no2 in nums:
        if no1 == no2:
            continue  # Don't compare with itself
        if no1 <= no2:
            greatest = False  # Not the greatest
            break
    if greatest:              #this is the variable tracking method used in car game also
        print(f"{no1} is greatest")
        break