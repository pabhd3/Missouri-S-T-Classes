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
for weight in range(0, 5):
    w[weight] = randint(-1000,1000)
    
print("Initial Weights = " + str(w))

# Test Math
for iteration in range(0, 5000):
    for entry in range(0, entries):
        #print("\nTesting Math")
        yCap = (w[0]*1)+(w[1]*int(PEPPERONI[entry]))+(w[2]*int(SAUSAGE[entry]))+(w[3]*int(MUSHROOM[entry]))+(w[4]*int(CHEESE[entry]))
        #print("yCap (before sigmoid) = " + str(yCap))
        yCapSigmoid = 1 / (1 + exp(-yCap))
        #print("yCap (after sigmoid) = " + str(yCapSigmoid))
        ERROR = int(ACCEPT[entry]) - yCapSigmoid
        #print("Error = " + str(ERROR))
        #print("Initial Weights = " + str(w))
        w[0] = w[0] + eta * (ERROR * yCapSigmoid)
        w[1] = w[1] + eta * (ERROR * yCapSigmoid * int(PEPPERONI[entry]))
        w[2] = w[2] + eta * (ERROR * yCapSigmoid * int(SAUSAGE[entry]))
        w[3] = w[3] + eta * (ERROR * yCapSigmoid * int(MUSHROOM[entry]))
        w[4] = w[4] + eta * (ERROR * yCapSigmoid * int(CHEESE[entry]))
        #print("Updated Weights = " + str(w))


# Output Part 2/2
print("\nUsing learning rate eta = " + str(eta))
print("After 5000 iterations:")
print("Sum of Squares Errors = " + str(LLE))
print("Weights:")
for i in range(0, 5):
    print("w" + str(i) + " = " + str(w[i]))