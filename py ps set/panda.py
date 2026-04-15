# create a dataframe and preform various operations data analysis fuctions along with graphical visualization datasheet
# (student performance ) 
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
# Create a sample dataframe
data = {
    'Student': ['Alice', 'Bob', 'Charlie', 'David', 'Eva'],
    'Math': [85, 92, 78, 90, 88],
    'Science': [89, 94, 80, 85, 91],
    'English': [90, 88, 84, 86, 92]
}
df = pd.DataFrame(data)
print("Dataframe:")
print(df)
# Calculate average scores for each student
df['Average'] = df[['Math', 'Science', 'English']].mean(axis=1)
print("\nDataframe with Average Scores:")
print(df)
arr1 = np.array([5, 15, 25, 35, 45])
arr2 = np.array([10, 20, 30, 40, 50])   
sum_arr = arr1 + arr2
print("Element-wise Addition of Two Arrays:")
print(sum_arr)
# Plot average scores
plt.bar(df['Student'], df['Average'], color='skyblue')
plt.xlabel('Student')
plt.ylabel('Average Score')
plt.title('Average Scores of Students')
plt.ylim(0, 100)
plt.show()
