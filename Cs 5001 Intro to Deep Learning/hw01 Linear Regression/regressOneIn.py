from random import randint

# Output Part 1/2
print("CS-5001 : HW#1 : Regression with one variable.")
print("Programmer: Peter Banko")
print("\nLearning rate eta = 0.001")
print("After 1500 iterations:")

# Bring in data
with open("./zdata.txt") as f:
    DATA = f.read().split()

# Pull only customers from Raw Data
customers = DATA[0::2]

# Pull only calories from Raw Data
calories = DATA[1::2]
count_calories = len(calories)

# Set Constants
entries = count_calories
eta = 0.001
LLE = 0

# Generate Random Weights
w = [0] * 2
w[0] = randint(0,20000)
w[1] = randint(0,20000)

# Set Error Weights to 0
wErr = [0] * 2

# Do 1500 iterations
for iteration in range(0,1500):
    # Loop through all entries in file
    for k in range(0, entries):
        # Calculate yCap and add to sum LLE
        yCap = int(w[0]) + (int(w[1]) * int(customers[k]))
        LLE = LLE + (int(calories[k]) - yCap)**2
        
        # Adjust Error Weights
        wErr[0] = wErr[0] + (int(calories[k]) - yCap)
        wErr[1] = wErr[1] + (int(calories[k]) - yCap)*int(customers[k])
        
    # Normalize Each Error Weight
    wErr[0] = (1/entries) * wErr[0]
    wErr[1] = (1/entries) * wErr[1]
    
    # Adjust the Weights
    w[0] = w[0] + eta * wErr[0]
    w[1] = w[1] + eta * wErr[1]

# Output Part 2/2
print("Sum of Squares Errors = " + str(LLE))
print("Weights:")
print("w0 = " + str(w[0]))
print("w1 = " + str(w[1]))