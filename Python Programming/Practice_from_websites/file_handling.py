f=open(r"C:\Users\SRI\vs code programs\Python Programming\Practice_from_websites\hellp.txt","w+")



f.seek(0)  # move cursor back to beginning

print(f.read())
f.close()