import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig, ax = plt.subplots()
ax.set_xlim(0, 10)
ax.set_ylim(0, 10)

ball, = ax.plot([], [], 'ro')

x = 0
y = 5

def update(frame):
    global x
    x += 0.1
    ball.set_data(x, y)
    return ball,

ani = animation.FuncAnimation(fig, update, frames=100, interval=50)

plt.show()
