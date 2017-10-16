# cs5001-hw02

Problem:
Dr. Farnsworth is exploring a new venture to fund his research: Pizzas for Cats!  Earth cats that is, 
not evil space cats. In order to develop the most tasty and acceptable toppings for his pizza-for-cats, 
Dr. Farnsworth has tested multiple different topping combinations against test subject cats, and 
recorded if the combination was or was not accepted by the test subjects. Now, he wants to train a 
predictor from the gathered data. Help Dr. Farnsworth build a predictor to know whether a topping 
combination will be accepted by cats. You will train a "single neuron" to perform logistic regression 
on the data collected by Dr. Farnsworth.

---------------------------------------------------------------------------------------------------------

Input:
The given file  pizzacatdata.txt  contains the data for this logistic regression problem. Each row of 
the data file consists of 5 boolean [0,1] values. The first 4 values indicate weather the pizza tested 
had Pepperoni, Sausage, Mushroom and Cheese, the last value indicates whether the cat subject accepted 
the pizza (1) or not (0).

---------------------------------------------------------------------------------------------------------

Gradient Descent:
Once again, you will implement gradient descent, and will use Least Squares as the error measurement 
for your neuron. However, this time the output of the neuron  Y^(e)  is given by:   

Y^(e) = sigmoid( ∑i=0n ( Wi * Xi(e) ) )

Where  sigmoid(x)  is the well known function:

sigmoid(x) = 1 / ( 1 + e^−x)		sigmoid'(x) = sigmoid(x)*(1 - sigmoid(x))

You shall implement incremental gradient descent. This means that you will be updating the weights 
after each example. Your program should perform 5000 iterations of the gradient descent. Initialize 
the weights randomly in the range [-1000...1000]. Experiment with different learning rates eta to find 
the best fit possible.

---------------------------------------------------------------------------------------------------------

Submission Guidelines:
Your submission will consists of the following components:
    1. Your program files.- Submit all necessary files. Your program should compile and run in the 
       Unix systems. Your program should read the input data from a file called  'pizzacatdata.txt', 
       (in the same location as your program), and produce output formatted like in the sample shown below.   
    2. A make file that should build and run your program.
    3. A report, in PDF format, in which you state the final weights of your neuron, the learning rate 
       you used to achieve such performance, state the sum of squares error of your final weights.

---------------------------------------------------------------------------------------------------------

Sample Output:
CS-5001 : HW#2 : Logistic Regression.
Programmer: Dr. Hubert J. Farnsworth
No cats were hurt gathering this data.

Using learning rate eta = 0.050
After 5000 iterations:
Sum of Squares Errors = 0.1234
Weights:
w0 = 3.1415
w1 = 42.0
w2 = 1.0
w3 = 777.0
w4 = 1.6180
