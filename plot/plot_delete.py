import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv("data/delete.csv", header=None, names=["Depth", "Duration"])

avg_data = data.groupby("Depth").agg({"Duration": "mean"}).reset_index()
plt.scatter(avg_data["Depth"], avg_data["Duration"], marker="o", color="b")

a = 1/5
b = 0
x = np.linspace(1, 50, 500)
y = a * x + b

plt.plot(x, y, color="r", linestyle="--", label="Logarithmic Growth")
plt.xlabel("Depth")
plt.ylabel("Duration")
plt.legend()

plt.show()