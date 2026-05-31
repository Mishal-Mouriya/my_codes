                          #revised on 31/5/25
buyer = input(print("is buyer good or bad"))
price = 100000
if buyer == "good":
    print("he has to reduce cost by 20%")
    price = price- 20/100*price
    print("price is $",price)
elif buyer == "bad":
    print("he has to reduce cost by 10%")
    price = price - 10/100*price
    print("price is $",price)
