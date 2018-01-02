Instructions
For this assignment you will submit (in the new usual way) multiple files. These files will contain a c++ program that you have named appropriately with appropriate extensions. You should have a file for your main (driver), a header for each class definition, an implementation file for each class. Submit in the usual way.

Background
To this point in the semester, your programs have been based on a fictional character, Moe Szyslak, from the Simpsons show.  No more.  Now we are going to get serious about programming.  With the introduction of the object-oriented programming paradigm, you are able now to write code that can be used to model any real, serious (and even real serious) situation.  Using classes, you can create C++ objects of your choosing to represent entities that will interact with each other so that you may discover the dynamics of a complex whole.  In the present assignment, you are asked to write the definitions of classes that will form the foundation of a tool box of objects usable to model any business endeavor, wherein you are going to be able to apply real-world solutions to real-world problems.  This may seem to you a rather overstated assertion, but hw #10 will show you that almost anything is possible with the versatility of C++.

Specifications
For this assignment, you are to create two classes and have appropriate files to contain them. You will also have a main function called a "driver".  A driver is a main function that has no purpose other than to test other parts of a program.  Since you are creating new classes, you need a driver to test their functionality.  We will not specify all that you should put in your driver, but we'll tell you this:  declare objects of the two class types, make sure all your constructors and member functions are tested.  You should have comments in the code stating what the functions' actions should result in.  

Not only are you satisfying the requirements for hw #9, but the classes you will create are going to be an integral part of hw #10.  In that assignment, you will modify what you produce here and you will add other classes and a main function that will  bring joy and enlightenment to your life.

The classes are described here:

The customer class:
    member variable:
        1. An array of strings to describe purchases. Size the array to 20.
        2. A short to represent the number of purchases currently in the above array.
        3. A float to represent spending money.
        4. A member to represent the customer's name.
    member functions:
        1. A default constructor that establishes an empty list of purchases, no name, and a random amount of money between and including $4.00 and $250.
        2. A constructor that will accept arguments for name and money, but sets purchases to 0.
        3. A purchase() function that returns a bool indicating whether or not the purchase was successful, and takes a string (describing the item purchased).  This function adds the item to the object's list of purchases if possible.
        4. An accessor function for the name and money members; a mutator for the money member.
        5. A print function that outputs the customer object's data on one line in this format:
            <name> has $<money> and purchases <item1> <item2> ....

The business class: 
    member variables:
        1. A string for the name of the business.
        2. A float to represent the amount of money in the cash register.
        3. A 10 item array of strings representing items the business sells.  (Yes, this is a small array, but it can always be expanded when necessary.)
        4. An array of 10 customer objects currently in the business.
        5. Two shorts to hold the sizes of the data in the two above mentioned arrays.
   member functions:
        1. A default constructor that sets the name of the business to the empty string, the cash to 0, the sizes of the arrays to 0.
        2. A constructor that allows the user to pass the business name, the amount of money in the register, sets the number of customers to 0, and then reads a file to stock its shelves (the array of items).  To make this work for this assignment, produce a data file with 7 item names in it.  You choose the item list; make it "clean" (you could make it very generic such as item1, item2, etc.).  You can either make the file name or stream a parameter or hard code those.
        3. A print function similar to the one for the customer class above, though not all on one line.  Make it pretty.  Output the business name and a list of customers and a list of shelf items.
        4. A function that is passed a customer so that the customer is put into the array customers in the business.  This emulates a customer coming into the business.
        5. A function called make_a_sale() that randomly "assigns" an item from the inventory of the business for each customer in the business to purchase.  Thus, each object in the customer array will in turn be sold (sort of a forced sale) an item chosen at random from the shelves.  The customer will be charged a fixed $40 for the item; the purchase happens only if the customer has the funds. Assume the business has an endless inventory (infinitely many of the items in its array of items to sell).

The driver:

Your driver should test the classes above thoroughly.  Do at least this:  declare 2 or 3 customers using your constructors.  Declare a business with a name and an inventory of stuff.  Have the customers enter the business.  Call the make_a_sale() function 2 or 3 times.  Then output the business to see what has happened.

Submit as usual.  There should be no user inputs.