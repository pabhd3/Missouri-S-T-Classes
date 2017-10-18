# Used to RNG
from random import randint

# Used for e^xrange
from math import e

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
X = [PEPPERONI,SAUSAGE,MUSHROOM,CHEESE]

# Entries
entries = len(ACCEPT)

# Learning Rate
eta = 0.050

# Sum of Squares Errors
LLE = 0

# Weights
w = [0, 0, 0, 0, 0]
for weight in range(0, 5):
    w[weight] = randint(-100,100)
    
print("Initial Weights = " + str(w))

# Calculations involving weights
for iteration in range(0, 5000):
    for entry in range(0, entries):
        yCap = (w[0]*1)+(w[1]*int(X[0][entry]))+(w[2]*int(X[1][entry]))+(w[3]*int(X[2][entry]))+(w[4]*int(X[3][entry]))
        yCapSigmoid = 1 / (1 + e**-yCap) 
        ERROR = int(ACCEPT[entry]) - yCapSigmoid
        w[0] = w[0] + (eta * ERROR * yCapSigmoid)
        w[1] = w[1] + eta * (ERROR * yCapSigmoid * int(X[0][entry]))
        w[2] = w[2] + eta * (ERROR * yCapSigmoid * int(X[1][entry]))
        w[3] = w[3] + eta * (ERROR * yCapSigmoid * int(X[2][entry]))
        w[4] = w[4] + eta * (ERROR * yCapSigmoid * int(X[3][entry]))

# Sum of Square Errors calculations
for entry in range(0, entries):
    yCap = (w[0]*1)+(w[1]*int(X[0][entry]))+(w[2]*int(X[1][entry]))+(w[3]*int(X[2][entry]))+(w[4]*int(X[3][entry]))
    yCapSigmoid = 1 / (1 + e**-yCap)   
    ERROR = int(ACCEPT[entry]) - yCapSigmoid
    LLE = LLE + (ERROR**2)
    
# Output Part 2/2
print("\nUsing learning rate eta = " + str(eta))
print("After 5000 iterations:")
print("Sum of Squares Errors = " + str(LLE))
print("Weights:")
for i in range(0, 5):
    print("w" + str(i) + " = " + str(w[i]))