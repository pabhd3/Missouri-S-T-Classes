# Used to RNG
from random import randint

# Used for e^xrange
from math import exp

# Output Part 1/2
print("CS-5001 : HW#2 : Logistic Regression.")
print("Programmer: Peter Banko")
print("No cats were hurt gathering this data.")

# Bring in DATA
with open("./pizzacatdata.txt") as f:
    DATA = f.read().split()

# Pull each topping from DATA
PEPPERONI = DATA[0::5]
SAUSAGE = DATA[1::5]
MUSHROOM = DATA[2::5]
CHEESE = DATA[3::5]
ACCEPT = DATA[4::5]

# Entries
entries = len(ACCEPT)

# Learning Rate
eta = 0.001

# Sum of Squares Errors
LLE = 0

# Weights
w = [0, 0, 0, 0, 0]
for weight in range(0,5):
    w[weight] = randint(-1000,1000)

# Test Math
yCap = (w[0]*1)+(w[1]*int(PEPPERONI[0]))+(w[2]*int(SAUSAGE[0]))+(w[3]*int(MUSHROOM[0]))+(w[4]*int(CHEESE[0]))
print("\nyCap (before sigmoid) = " + str(yCap))
yCapSigmoid = 1 / (1 + exp(-yCap))
print("yCap (after sigmoid) = " + str(yCapSigmoid))
ERROR = int(ACCEPT[0]) - yCapSigmoid
print("Error = " + str(ERROR))


# Output Part 2/2
print("\nUsing learning rate eta = " + str(eta))
print("After 5000 iterations:")
print("Sum of Squares Errors = " + str(LLE))
print("Weights:")
for i in range(0, 5):
    print("w" + str(i) + " = " + str(w[i]))