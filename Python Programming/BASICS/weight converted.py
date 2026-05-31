print(" this is a wight convertor which converts pounds and kilos to each other glad to use our services")
weight= int(input(print("what is your weight?")))
unit= input(print("what is the unit? state k for kilos and l for pounds"))
if unit == "k":
    weight= weight * 2.205
    print("weight is pound ",weight)
elif unit == "l":
    weight= weight * 0.45
    print("weight is kilo ",weight)
    #program over lol