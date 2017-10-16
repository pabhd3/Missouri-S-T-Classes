# Used to RNG
from random import randint

# Output Part 1/2
print("CS-5001 : HW#2 : Logistic Regression.")
print("Programmer: Peter Banko")
print("No cats were hurt gathering this data.")

# Learning Rate
eta = 0.001
LLE = 0
w = [0, 0, 0, 0, 0]

# Output Part 2/2
print("\nUsing learning rate eta = " + str(eta))
print("After 5000 iterations:")
print("Sum of Squares Errors = " + str(LLE))
print("Weights:")
for i in range(0, 5):
    print("w" + str(i) + " = " + str(w[i]))