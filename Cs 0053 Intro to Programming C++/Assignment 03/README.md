Instructions
For this assignment, you will submit a single C++ compilable file containing a program written in C++.

Background
Ok, so Moe liked the work that you did for him and now wants you to code another project.  He is lazy and fairly unp .... no, very unpleasant.  (You can see it in his face.)  So Moe wants a computer stationed at the door of his bar so that patrons entering will run the "Greeter Program".  It will ask questions of each potential patron, and then either welcome them in or tell them to leave.

Specifications
Your program will behave as follows: 
    * First prompt/read in a name (first only is fine).  
    * The patron (always referred hereafter by name) is then asked if he/she/it is a "teetotaler"1 and promptly thrown out if the answer is yes. 
    * If not, they are asked their age and asked to leave if they are not 21 or older. 
    * Then they are asked if they intend to drink beer, soda, or hard liquor. 
        * The affirmative on soda will get them a ticket out the door with a "we don't soyrv you sissies in dis place!" response. 
        * Beer and hard-stuff drinkers are welcomed, but questioned how much money they have on them. 

With this info, Moe (your program, actually) will tell them how many beers (for beer drinkers) or how many drinks (for hard-stuff drinkers) they can buy with that amount of money. The program will then inquire as to how many drinks they intend to buy. If the answer is less than the maximum number of drinks they can buy with their money, they will promptly be thrown in the gutter ("come back when you want to spend all your money!"). Otherwise, your program will tell them to "come right in, step up to the bar!" If the patron has not enough money to buy even one drink, throw them out with a "get outta here, ya bum!".  For any cases above where I haven't specified what is said to the customer, you make up something appropriate.  If the patron is "Barney", just respond with, "C'mon in Barney". 

This will end the interaction with a given potential patron. Your program should then prompt for another patron by saying something like, "Anybody else there??". An affirmative answer will have the user go through the entire "interview" again, and end the program otherwise. At any time in the interview a potential patron is "asked to leave", this prompt for another patron is invoked. 

At Moe's:

* beers are $2.00 ea.
* hard liquor drinks are all $4.25 ea.

Remember: When writing your code, be sure to:

* Use meaningful variable names.
* Use proper spacing for indentations.
* Use constant variable declarations where appropriate.
* Include the comment block at the head of your file.
* Comment code that needs it.
* Be literate in your welcoming/signing-off messages and prompts and output.

Note: You are expected to check the inputs from the user for range acceptance. What that means is that whenever appropriate, a input value should be checked for validity. For example, if the user inputs -8 or 213 for their age, then they are to be re-prompted. So what are acceptable ranges? You decide this....and make it a good decision! To do this range checking and the required re-prompting for new patrons, you will need to use loops.  We may not have covered loops by the time this assignment is posted, but we will very soon.  You can still get started on the coding for this program.

Also, since you will be displaying dollar amounts, it's bad form to have $3.50 come out as $3.5. So, put the following code at the top of your main after declarations and it will force exactly two decimal places to be shown always.

             cout.setf(ios::fixed); 
             cout.setf(ios::showpoint); 
             cout.precision(2); 

We'll explain where this code comes from later in the semester.

Optional 
You can optionally display how much "change" patrons (who drink) leave the bar with. For example, suppose a patron comes in with $4.60 and drinks beers. He/She/It would have two beers with $0.60 left over. You would report this 60 cents.

Submitting
When you submit:
* enter the bar not as a teetotaler, but a legal beer drinker with $21.45 in your pocket. Report you intend to drink 10 beers.
* next patron is to be a teetotaler.
* next patron is to be a legal soda drinker.
* no more patrons