import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv("data/height.csv", header=None, names=["Nodes", "Height"])

avg_data = data.groupby("Nodes").agg({"Height": "mean"}).reset_index()
plt.scatter(avg_data["Nodes"], avg_data["Height"], marker="o", color="b")

a = 1
b = 0
x = np.linspace(1, 20, 100)
y = a * x + b

plt.plot(x, y, color="r", linestyle="--", label="Logarithmic Growth")
plt.xlabel("Number of Nodes")
plt.ylabel("Average Height")
plt.legend()

plt.show()