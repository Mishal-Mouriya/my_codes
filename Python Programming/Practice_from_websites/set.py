#This qusetion i made so many mistakes..first one is i did in list instead of sets
#through sets this qusstion is very easy and i highly recommend to go through this

#This deals with power of sets go through and u will understand



# ==========================================
# QUESTION 1 — LOVE MEET
# ==========================================
#
# Bob and Alice travel through different Paris districts during the day.
#
# Write a function:
#
#     love_meet(bob, alice)
#
# that takes two lists and returns a SET of districts
# both Bob and Alice visit.
#
# Example:
#
# alice = ['Ⅱ', 'Ⅳ', 'ⅩⅠⅩ', 'ⅩⅤ', 'Ⅳ', 'Ⅱ']
# bob   = ['Ⅳ', 'Ⅲ', 'Ⅱ', 'ⅩⅩ', 'Ⅱ', 'ⅩⅩ']
#
# Output:
# {'Ⅱ', 'Ⅳ'}
#
# ==========================================
# SOLUTION
# ==========================================

def love_meet(bob, alice):

    # Convert both lists into sets
    # & means intersection (common elements)

    return set(bob) & set(alice)



# ==========================================
# QUESTION 2 — AFFAIR MEET
# ==========================================
#
# Alice now wants to secretly meet Silvester.
#
# Write a function:
#
#     affair_meet(bob, alice, silvester)
#
# that returns a SET of districts where:
#
# 1. Alice and Silvester BOTH go
# 2. Bob does NOT go
#
# Example:
#
# alice = ['Ⅱ', 'Ⅳ', 'Ⅱ', 'ⅩⅠⅩ', 'ⅩⅤ', 'Ⅳ', 'Ⅲ']
# bob = ['Ⅳ', 'Ⅲ', 'Ⅱ', 'ⅩⅩ', 'Ⅱ', 'ⅩⅩ']
# silvester = ['ⅩVⅢ', 'ⅩⅠⅩ', 'Ⅲ', 'Ⅰ', 'Ⅲ', 'ⅩVⅢ']
#
# Output:
# {'ⅩⅠⅩ'}
#
# ==========================================
# SOLUTION
# ==========================================

def affair_meet(bob, alice, silvester):

    # Find common places between Alice and Silvester
    # Then remove places Bob visits

    return (set(alice) & set(silvester)) - set(bob)



# ==========================================
# TESTING
# ==========================================

alice = ['Ⅱ', 'Ⅳ', 'ⅩⅠⅩ', 'ⅩⅤ', 'Ⅳ', 'Ⅱ']
bob = ['Ⅳ', 'Ⅲ', 'Ⅱ', 'ⅩⅩ', 'Ⅱ', 'ⅩⅩ']

print(love_meet(bob, alice))


alice = ['Ⅱ', 'Ⅳ', 'Ⅱ', 'ⅩⅠⅩ', 'ⅩⅤ', 'Ⅳ', 'Ⅲ']
bob = ['Ⅳ', 'Ⅲ', 'Ⅱ', 'ⅩⅩ', 'Ⅱ', 'ⅩⅩ']
silvester = ['ⅩVⅢ', 'ⅩⅠⅩ', 'Ⅲ', 'Ⅰ', 'Ⅲ', 'ⅩVⅢ']

print(affair_meet(bob, alice, silvester))