import numpy as np
import pandas as pd

data = {
    "Student_ID": [101, 102, 103, 104, 105, 106],
    "Study_Hours": [2, 4, 6, 3, 5, 7],
    "Attendance_Percent": [75, 85, 95, 80, 90, 98],
    "Internal_Marks": [18, 22, 27, 20, 25, 28],
    "Final_Marks": [65, 72, 85, 68, 78, 90]
}

df = pd.DataFrame(data)
print(df)


print ()
print(df.head(3))
print ("")  

print()
print (df.tail(2))
print()  


# crerate a pandas dataframe using the above data 
# display the first 3 rows and last 2 rows of the dataframe
# mean of study hours and attendance and final marks
# maximum and minimum of final marks
# add a new column performance level 
# excellent if final marks > 85
# good if final marks between 70 and 85
# average if final marks between 50 and 70
# poor if final marks < 50
mean_study_hours = df['Study_Hours'].mean()
mean_attendance = df['Attendance_Percent'].mean()
mean_final_marks = df['Final_Marks'].mean()     
print("Mean Study Hours:", mean_study_hours)
print("Mean Attendance Percent:", mean_attendance)
print("Mean Final Marks:", mean_final_marks)
max_final_marks = df['Final_Marks'].max()
min_final_marks = df['Final_Marks'].min()
print("Maximum Final Marks:", max_final_marks)
print("Minimum Final Marks:", min_final_marks)

def performance_level(marks):
    if marks > 85:
        return 'Excellent'
    elif marks > 70:
        return 'Good'
    elif marks > 50:
        return 'Average'
    else:
        return 'Poor'
df['Performance_Level'] = df['Final_Marks'].apply(performance_level)
print("\nDataframe with Performance Level:")
print(df)