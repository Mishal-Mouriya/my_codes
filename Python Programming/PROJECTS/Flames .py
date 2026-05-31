# 💖 FLAMES Game - by chromaster & ChatGPT 💖
# Date: 10/06/2025


name_user = input("Enter your name: ").lower().replace(" ", "")                 #new1
name_crush = input("Enter your crush's name: ").lower().replace(" ", "")


for ch in name_user[:]:  # [:] is used to safely iterate over a copy
    if ch in name_crush:
        name_user = name_user.replace(ch, "", 1)   # remove one occurrence    #new2
        name_crush = name_crush.replace(ch, "", 1)


total_remaining = len(name_user + name_crush)


flames = ["Friends", "Lovers", "Affectionate", "Marriage", "Enemies", "Siblings"]


while len(flames) > 1:
    # Calculate index to remove based on count
    index = (total_remaining % len(flames)) - 1

    if index >= 0:
        # Split and rotate the list like a circle
        right = flames[:index]         # from start to item before index
        left = flames[index+1:]        # from item after index to end                         #new3
        flames = left + right          # new rotated list (excluding the removed one)
    else:
        # If index is -1, remove the last item
        flames = flames[:len(flames)-1]

# 🎉 Step 6: Show result!
print("Your relationship status is:", flames[0])
