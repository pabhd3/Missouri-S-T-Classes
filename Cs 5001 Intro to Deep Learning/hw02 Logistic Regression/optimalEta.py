import time
from catPizzaReg import logisticReg

# This is designed to calculate the best learning rate
#    tp use in Homework 02: Logistic Regression

# Measure time to run
start_time = time.time()

etaData = {}

for e in range(1,50):
    eta = e/100
    etaSum = 0
    for iteration in range(0,100):
        etaLLE = logisticReg(eta)
        etaSum = etaSum + etaLLE[1]
    etaData[eta] = etaSum
    print("Eta = " + str(eta) + " LLE Sum = " + str(etaSum))

# Print out Best Eta
optimalEta = min(etaData, key=etaData.get)
print("\nOptimal Eta is " + str(optimalEta) + "\n")

# Print out elapsed time
end_time = time.time()
elapsed_time = end_time - start_time
print(str(elapsed_time) + " seconds elapsed")