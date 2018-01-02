Instructions
For this assignment, you will submit a single C++ compilable file containing a program written in C++.

Background
Your last assignment was to fulfill another programming contract with Moe. You did well and now Moe has money, but still no brains. So, Moe's going back to skool ... to gradeschool ... to get his 8th grade GED. You see, Moe never finished grade school. He got into a scrape with the law because he killed one of the Little Rascals, a group he used to be a member of!   Moe's a bit worried about the math that he'll be trying to learn.

Specifications
Your program is to be menu driven (i.e. has a main menu). You are required to use a switch-case statement
for implementing the functionality of the menu. The menu will have five choices:
			Menu
	1. Enter Fractions
	2. Add Fractions
	3. Divide Fractions
	4. Simplify Fractions
	5. Quit

You are to use functions for this assignment and they should follow the following prescriptions.
    * Desc: Greetings. This function is simply to output a welcome message.
    Input: none
    Output: Returns nothing, but outputs message to screen.
    * Desc: Goodbyes. This function is simply to output a parting message.
    Input: None
    Output: Returns nothing, but outputs message to screen.
    * Desc: Display Menu function. This function is to display the menu and return valid character choice for that menu. 
    Input: None
    Output: Returns character representing a valid menu choice.
    * Desc: Enter fractions. This function will store keyboard input to memory for two fractions that are read in by user.
    Input: None.
    Output: Returns user input to calling function.
    * Desc: Display fraction. This function is to display to the screen a fraction (sent to it) in standard format: a/b
    Input: A fraction.
    Output: Returns nothing, but outputs the fraction to screen.
    * Desc: Add fraction. This function will compute the (unsimplified) sum of the two fractions passed to it and return that result.
    Input: Two fractions.
    Output: a fraction
    * Desc: Divide fraction.This function will compute the (unsimplified) quotient of the two fractions passed to it and return that result.
    Input: Two fractions.
    Output: a fraction
    * Desc: The simplify function. This function will "simplify" a fraction that is passed to it.
    Input: A fraction.
    Output: The input fraction is simplified.

ou are expected to use all of these functions. If you believe other functions are warranted, you may include them.
Notes: No option (except quit) should be allowed unless fractions are entered. Anytime Add or Divide are chosen, the resultant fraction displayed should be automatically simplified. The simplify menu choice will display the simplified forms of both of the entered fractions.

It should be emphasized here that you have some latitude in how you implement these functions. Be careful how you design your functions, especially when using reference parameters.

Specs on the Specs 

To help with your endeavor, here is an algorithm for finding the greatest common divisor of two numbers:

1. Enter two numbers.
2. Label the larger of the two, Big and the smaller of the two, Small
3. Set Answer = Big mod Small 
4. if Answer is not equal to zero
    a. Big = Small
    b. Small = Answer
    c. Go to step 3
5. else Small is the greatest common divisor of the two numbers.

When you submit
1. choose option 3
2. choose option 1 and enter 3/7 and 15/25
3. choose option 4
4. choose option 2
5. choose option 3
6. quit

DO NOT UNDERESTIMATE THE DIFFICULTY OF THIS ASSIGNMENT!