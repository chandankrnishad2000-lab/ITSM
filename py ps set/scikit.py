import numpy as np 
import pandas as pd
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

data = {
    'train size': [100, 200, 300, 400, 500],
    'train number':[12321,13231.32421,13123,13231,12312]
    
}
df=pd.DataFrame(data)
print(df)   
X = df[['train size']]
y = df['train number']
model=LinearRegression()
model.fit(X,y)
new_train_size = np.array([[600]])
predicted_train_number = model.predict(new_train_size)
print(f"Predicted train number for train size 600: {predicted_train_number[0]}")

plt.scatter(X, y, color='blue', label='Data Points')
plt.plot(X, model.predict(X), color='pink', label='Regression Line')
plt.xlabel('Train Size')
plt.ylabel('Train Number')
plt.title('Train Size vs Train Number')
plt.legend()
plt.show()  