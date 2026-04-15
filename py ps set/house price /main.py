import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt 

# Load dataset
df = pd.read_csv("House Price Prediction Dataset.csv")

print(df.head())

area = df[['Area']]
price = df['Price']

model = LinearRegression()
model.fit(area, price)

predicted_price = model.predict([[2000]])
print("Predicted price for area 2000:", predicted_price[0])

plt.scatter(area, price)
plt.plot(area, model.predict(area))
plt.show()