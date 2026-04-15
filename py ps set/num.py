# import numpy as np
# a = [8,9,3,5,6,3,]
# print (np.array(a))

# import numpy as np
# a = np.array([1,2,3,4,5])
# print (np.mean(a))


# import numpy as np 
# a = np.array([1,2,3,4,5])
# print (np.median(a))

# create a 1D array of numbers from 1 to 10
import numpy as np

arr = np.arange(1, 11)
print(arr)

# create an array of numbers from 5 to 50 with a step of 5
import numpy as np

arr = np.arange(5, 51, 5)
print(arr)
# create a 2D array and reshape it to a 1D array
import numpy as np

arr_2d = np.array([[1, 2, 3],
                   [4, 5, 6],
                   [7, 8, 9]])


arr_1d = arr_2d.reshape(9)

print("2D Array:")
print(arr_2d)

print("1D Array:")
print(arr_1d)

# create a zeros array of shape (4, 2) and a ones array of shape (2, 4)
import numpy as np


zeros_arr = np.zeros((4, 2))


ones_arr = np.ones((2, 4))

print("Zeros Array (4x2):")
print(zeros_arr)

print("\nOnes Array (2x4):")
print(ones_arr)

#perform element-wise addition of two arrays
import numpy as np


arr1 = np.array([1, 2, 3, 4, 5])
arr2 = np.array([6, 7, 8, 9, 10])

result = arr1 + arr2

print("Array 1:", arr1)
print("Array 2:", arr2)
print("Result:", result)

# perform element-wise multiplication of two arrays

import numpy as np


arr1 = np.array([1, 2, 3, 4, 5])
arr2 = np.array([2, 4, 6, 8, 10])


result = arr1 * arr2

print("Array 1:", arr1)
print("Array 2:", arr2)
print("Result:", result)


# calculate the square root of each element in an array
import numpy as np


arr = np.array([1, 4, 9, 16, 25])


result = np.sqrt(arr)

print("Original Array:", arr)
print("Square Root Array:", result)

# find the maximum and minimum values in an array
import numpy as np  
arr = np.array([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5])

max_value = np.max(arr)
min_value = np.min(arr)

print("Array:", arr)
print("Maximum Value:", max_value)
print("Minimum Value:", min_value)

# calculate the sum,mean ,and standard deviation of an array
import numpy as np  
arr = np.array([1, 2, 3, 4, 5])

sum_value = np.sum(arr)
mean_value = np.mean(arr)
std_deviation = np.std(arr)

print("Array:", arr)
print("Sum:", sum_value)
print("Mean:", mean_value)
print("Standard Deviation:", std_deviation)
print("Result:", result)



