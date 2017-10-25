import time
from datetime import timedelta
import argparse
from catPizzaReg import logisticReg

# This is designed to calculate the best learning rate
#    tp use in Homework 02: Logistic Regression

# Measure time to run

# Set Up Argparse
parser = argparse.ArgumentParser(description='Test Learning Rates')
parser.add_argument('start', metavar='Start', type=float,
                    help='Starting Value')
parser.add_argument('stop', metavar='Stop', type=float,
                    help='Ending Value')
parser.add_argument('step', metavar='Step', type=float,
                    help='Step Size')
parser.add_argument('-s', type=bool, default=False,
                    help='Do you want to save the results?')
# Parse the arguments
args = parser.parse_args()

# Set the arguments as variables
START = args.start
STOP = args.stop
STEP = args.step
SAVE = args.s

start_time = time.time()

if(SAVE):
    f = open('EtaData.txt', 'w')

eta = START
etaData = {}

# Eta Calculations
while(eta <= STOP):
    etaSum = 0
    for iteration in range(0,100):
        etaLLE = logisticReg(eta)
        etaSum = etaSum + etaLLE[1]
    etaData[eta] = etaSum
    if(SAVE):
        f.write("Eta = " + str(eta) + " LLE Sum = " + str(etaSum) + "\n")
    print("Eta = " + str(eta) + " LLE Sum = " + str(etaSum))
    eta = eta + STEP

# Print out Best Eta
optimalEta = min(etaData, key=etaData.get)
if(SAVE):
    f.write("\nOptimal Eta is " + str(optimalEta) + "\n")
print("\nOptimal Eta is " + str(optimalEta) + "\n")

# Print out elapsed time
end_time = time.time()
elapsed_time = end_time - start_time

if(SAVE):
    f.write("\nTime Elapsed: " + str(timedelta(seconds=elapsed_time)) + " (Hr:Min:Sec)")
print("\nTime Elapsed: " + str(timedelta(seconds=elapsed_time)) + " (Hr:Min:Sec)")

if(SAVE):
    f.close()