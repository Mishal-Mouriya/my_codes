import matplotlib.pyplot as plt

fig,ax = plt.subplots()                           #here fig is collection plots and ax is one plot

ax.plot([1,4,9,16,25],[1,2,3,4,5],linewidth=9)
'''  first list acts as x and scond as y 
     u can also define width of line'''

ax.tick_params(labelsize=9 ) #ticks are the scale now this gives scale size

ax.set_title("GOOD",fontsize=10)  #self explanatory
ax.set_xlabel("BAD",fontsize=8)
ax.set_ylabel("UGLY",fontsize=8)

    #shows the table

#2nd graph

fig,ax1 = plt.subplots()
ax1.scatter(range(10),range(10),c='red',s=10)
plt.show()