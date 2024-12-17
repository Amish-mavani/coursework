import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
 
# Load the dataset
df = pd.read_csv('Salary_Data.csv')
df.info()
 
df.plot(x="YearsExperience", y=["Salary"], kind="scatter")
 
#YearsExperience = [1.1, 1.3, 1.5, 2.0, 2.2, 2.9, 3.0, 3.2, 3.2, 3.7, 3.9, 4.0, 4.0, 4.1, 4.5, 4.9, 5.1, 5.3, 5.9, 6.0, 6.8, 7.1, 7.9, 8.2, 8.7, 9.0, 9.5, 9.6, 10.3, 10.5]
#Salary = [39343.00, 46205.00,37731.00, 43525.00, 39891.00, 56642.00, 60150.00, 54445.00, 64445.00, 57189.00, 63218.00, 55794.00, 56957.00, 57081.00, 61111.00, 67938.00, 66029.00, 83088.00, 81363.00, 93940.00, 91738.00, 98273.00, 101302.00,  113812.00,  109431.00,  105582.00,  116969.00,  112635.00, 122391.00, 121872.00 ]
 
# Sample data
X = np.array([1.1, 1.3, 1.5, 2.0, 2.2, 2.9, 3.0, 3.2, 3.2, 3.7, 3.9, 4.0, 4.0, 4.1, 4.5, 4.9, 5.1, 5.3, 5.9, 6.0, 6.8, 7.1, 7.9, 8.2, 8.7, 9.0, 9.5, 9.6, 10.3, 10.5])
Y = np.array([39343.00, 46205.00,37731.00, 43525.00,  39891.00, 56642.00, 60150.00, 54445.00, 64445.00, 57189.00, 63218.00, 55794.00, 56957.00, 57081.00, 61111.00, 67938.00, 66029.00, 83088.00, 81363.00, 93940.00, 91738.00, 98273.00, 101302.00,  113812.00,  109431.00,  105582.00,  116969.00,  112635.00, 122391.00, 121872.00 ])
 
# Calculate mean of X and Y
mean_x = np.mean(X)
mean_y = np.mean(Y)
 
# Calculate slope and intercept for the best-fitted line
m = np.sum((X - mean_x) * (Y - mean_y)) / np.sum((X - mean_x)**2)
c = mean_y - m * mean_x
 
# Plot the input-output relation and the best-fitted line
plt.scatter(X, Y)
plt.plot(X, m * X + c, color='red')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Best-Fitted Line')
plt.grid(True)
plt.show()
