import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt


data = {
    "StudyHours": [1,2,3,4,5,6,7,8],
    "Pass": [0,0,0,1,1,1,1,1]
}

df = pd.DataFrame(data)


print(df.head())


print(df.info())


print(df.isnull().sum())


X = df[["StudyHours"]]
y = df["Pass"]

X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=42)


model = LogisticRegression()
model.fit(X_train,y_train)


print("Coefficient:",model.coef_)
print("Intercept:",model.intercept_)


y_pred = model.predict(X_test)


acc = accuracy_score(y_test,y_pred)
print("Accuracy:",acc)


new_input = [[5]]
prediction = model.predict(new_input)
print("Prediction for 5 study hours:",prediction)


plt.scatter(X,y)
plt.xlabel("Study Hours")
plt.ylabel("Pass/Fail")
plt.title("Logistic Regression Visualization")
plt.show()