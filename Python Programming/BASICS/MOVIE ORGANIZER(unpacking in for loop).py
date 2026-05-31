 [[[[[[[ MOVIE ORGANIZER ]]]]]]]


                       #revised on 31/5/25
print('THIS IS A MOVIE ORGANIZER THAT LETS U CHOOSE UR MOVIE')
movies = [
    ("Inception", "sci-Fi", 148, 8.8),
    ("Spirited Away", "animation", 125, 8.6),
    ("The Dark Knight", "action", 152, 9.0),
    ("Parasite", "thriller", 132, 8.6),
    ("Your Name", "animation", 106, 8.4)
]
genre1 =input("enter ur preferred genre ").lower()
found=False
for  (name, genre , watchtime , rating) in movies:
    if genre1 == genre:
        print(f" {name} - {rating}")
        found=True
        continue
    else:
        continue
if not found:            #AGAIN VARIABLE TRACKING METHOD IS APPLIED HERE
    print(' YOur typed genre is not present in the movies list')
rating1 = int(input("enter min rating of movie: "))
for  (name, genre , watchtime , rating) in movies:
    if rating > rating1:
        print(f" {name} - {genre}")
        continue
    else:
        continue
print("Thank you for playing")