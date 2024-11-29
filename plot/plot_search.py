import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv("data/search.csv", header=None, names=["Depth", "Duration"])

avg_data = data.groupby("Depth").agg({"Duration": "mean"}).reset_index()
plt.scatter(avg_data["Depth"], avg_data["Duration"], marker="o", color="b")

a = 1/2
b = 0
x = np.linspace(1, 50, 500)
y = a * np.log(x + b)

plt.plot(x, y, color="r", linestyle="--", label="Logarithmic Growth")
plt.xlabel("Number of Nodes")
plt.ylabel("Average Height")
plt.legend()

plt.show()