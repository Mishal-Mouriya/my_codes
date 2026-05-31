import plotly.express as px
from dieclass import Die
from random import randint
import plotly.io as pio
pio.renderers.default = "browser"


# using and storing results of 1000 throws
die = Die(6)
results = []

for throw in range(1000):
    result = die.roll_dice()  # ← fixed
    results.append(result)

# now let's find frequency of each outcome
outcomes = range(1,   die.no_of_fases + 1)  
frequency = [results.count(x) for x in outcomes]

print(frequency)

# now plotting basic graph
title = "Plotting the Frequency of Outcomes"
labels = {"x": "Outcomes", "y": "Frequency"}  

fig = px.bar(x=outcomes, y=frequency, title=title, labels=labels)
fig.update_layout(xaxis_dtick=1)

fig.write_html("dice_plot.html", auto_open=True)
