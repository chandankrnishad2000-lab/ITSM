import pandas as pd
import numpy as np


data = {
    "Student": ["S1", "S2", "S3", "S4", "S5"],
    "Study_Hours": [1, 4, np.nan, 6, 7],
    "Marks": [30, 50, 55, np.nan, 85]
}

df = pd.DataFrame(data)

print("Original Dataset")
print(df)


print("\nMissing Values:")
print(df.isnull())


df["Study_Hours"].fillna(df["Study_Hours"].mean(), inplace=True)
df["Marks"].fillna(df["Marks"].mean(), inplace=True)

print("\nDataset After Replacing Missing Values")
print(df)