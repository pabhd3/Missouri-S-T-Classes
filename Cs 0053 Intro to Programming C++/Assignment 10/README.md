Instructions: For this assignment you will submit multiple files, but not quite in the usual way. These files will contain a c++ program that you have named appropriately with appropriate extensions. You should have a file for your main (driver), a header for each class definition, an implementation file for each class.

Background: As stated in background for assignment #9, the classes you developed there were to be used in assignment #10.  Here you will extend those classes, add other classes, and use the whole mess in a very serious and productive manner.  Moe - you remember him, don't you - and another enterprising gentleman with abundant entrepreneurial spirit, Comic Book Guy (henceforth referred to as either Mr. Guy or CBG), own business in, and have customers from, Springfield. But they sometimes find themselves with competing interests.  That is, some of Mr. Guy's customers and many of Moe's customers just can't seem to get along well.  So you're going to use your coding skills to write a simulation of the interactions (fights) between customers of both of these businesses.  

Specifications:  For this assignment, you are to modify the classes business and customer from hw #9 in the following ways:

The customer class:
    member variables:
        1, The base type of the purchases array will be product, a new type (struct) described below.
        2. Add a new member called happiness that will indicate the general disposition of the object.  Happiness values will range from 0 (total despair) to 100 (nirvana).  You could call this member satisfaction, if you wanted to sound serious.  
        3. A member indicating whether they will shop at Moe's or at CBG's store.  We'll refer to this as their "inclination". 
        4.Any other member variables you think are essential to the definition of a customer in general.  It is up to you.
    member functions:
        1. Your default constructor should construct a customer object by randomly assigning money as before and Happiness randomly from 0 to 100. Name and inclination is not set here.  These member values will have to be set by mutators after object creation.
        2. The purchase() function described in hw #9 is to be removed.  In its place, create a buy_something() function that returns a bool (success or not).  This function will be called when a customer is in a business and the business calls its sell_stuff() function.  When the buy_something() function is called, the customer object must first decide (50-50) whether or not to buy something from the business.  If it does, then it will choose at random one of the products in the business, then check to see if they can afford it, and copy that product into their array of purchases and decrement their money.  If the purchase actually happens, your code must increase the business'sss's money.  Remember:  a customer  can only make the purchase if they have enough money and room in their array (a euphemism for "pocket"). Also, this function should increment Happiness by 15 if successful, decrement by 10 if not.
        3. A throw() function that simulates throwing an object at another customer (or potentially yourself).  This is described below.
        4. A rob() function that simulates the act of robbing from another customer.  Again, this is described below.
        5. Overload (as a friend) the insertion operator << so that you can output a customer object like normal people can.  Have it format output as in the print() function; then get rid of the print().
        6. Appropriate accessors and mutators.

The business class:
    member variables:
        * The array of items to sell will be base type product. 
    member functions:
        * The function from hw 9 that adds a customer into the business will henceforth and forthwith be called addCustomer().  This function is otherwise the same.
        * A sell_stuff() function that will walk down its array of customers to see if they are going buy something. Quite naturally, it will call each customer's buy_something() function.  Once the customer's buy_something() function determines if and what it buys, the sell_stuff() function must take the action to transfer the product to the customer and transfer the funds appropriately.
        * A customers_leave() function that has as a parameter an array of customers and an int for the number of customers in the array.  This function will copy all the customers in the business into that array, thus emulating the customers leaving the business and going into the street.  Be sure to make this function reflect what is happening in the business as well as the street.

The product struct:
    member variables:
        * string for name of the product
        * float for the price of the product       

The Main function for this assignment is going to be of your design, but it has to accomplish the following.  You will create two businesses, one for Moe's Bar and one for Comic Book Guy's store.  You will have an array of 20 customers. Note:  when you create an array of a user-defined type (customer), your default constructor is called for each object in the array.  Your default only gives random money and Happiness.  So, your code will have to walk down this array of customers and give them all names and inclination.  To do this, connect to a file (below) and read in those values for each of the customers in this array.  Then, all of these customers will enter the appropriate business and will make purchases (or not), making their Happiness coefficients go up (or down).  They will all then exit the businesses they are in and go into the street (where they started) and "interact" with the other people (customers). Of course, people being people, they will begin by milling about, moving up and down the street, mixing, talking.  To emulate that, just shuffle the array1.  (You don't have to make them talk.)  The interactions will follow these rules:
    1. Start with the first customer in the array.  Have him/her pick another person in the array at random.  If that person is of the same inclination (frequents the same business), then he steals a purchase from him and his happiness increases by 25 and the victim's happiness decreases by 20.  The item stolen has to be copied into the perp's array of purchases.  If that person is of the other inclination (different business), then he throws one of his purchases at them (it just falls into the street and is forgotten) and the perp's Happiness increases by 5 and the victim's decreases by 20.  These interactions are either going to be successful or not depending on ownership of something to throw or steal.  A theft will be successful if the victim has something to steal and the perp has a place to put it.  A throw is successful if the perp has something to throw.  If a throw is not successful, the perp's Happiness goes down by 25 and the victim's is unchanged.  Also, if a theft is unsuccessful, then the perp's Happiness goes down by 5 and the intended victim's is again unchanged.
    2. If a person tries to steal from or throw at themselves, then so be it.  What an idiot.
    3. Do step one for each succeeding person in the array.

At this point, the array of customers will again enter their respective businesses and repeat the whole process.  Now, whenever the array customers is copied into the stores, this is a good time to determine their fates relative to their Happiness coefficient.  Thus, if a person's Happiness is below 10, they are desperately unhappy and will get shipped off to the House of Desperation in Shelbyville.  If their Happiness is 90 or above, they have reached some sort of nirvana and decide on their own to go to Shelbyville, where they can lord over the depairati in the House of Desperation.  In either case, remove these people from the array of customers.  

The cycle will repeat until either there is only one remaining customer in Springfield (the rest have migrated to Shellbyville) or 20 cycles have past, whichever comes first.  At this time, a "winner" will be determined:  Tally the Happiness coefficient for each group of customers and the greater identifies the winners/losers.....well, they're all losers...but I digress.

Output: 
    1. Output the initial array of customers.  [ex.  Lenny has $56 with Happiness 88]
    2. Output each purchase.  [ex. Homer purchases a beer bottle for $4]
    3. Output each interaction.  [ex. Krusty throws a barstool at Milhouse]
    4. Output the result of anyone leaving Springfield.  [ex.  Smithers falls desperately hopeless at level 7 and is shipped to Shelbyville House of Desperation.]
    5. At the end of each round of interactions, output the whole array of customers.  [ex. Homer has $49 with Happiness 87 and has barstool, beer bottle, pickled egg]
        Note: the output in 1 and 5 are the same.
    6. Output the final results of the simulation....of a real-world business adventure!  (Who wins, why, what are the implications for the world economy, etc)
    
Optional:
You can create a proprietor class and have each business contain a proprietor who does stuff.  Perhaps he can have a randomly invoked embezzle  function, or he might randomly throw_stuff() at his customers.  If you decide to do this, have fun!!

SUBMITTING:
For this project, you are allowed to work in groups of 1, 2 or 3, but not 0.  Five is right out!  Be sure to put all names of group members in all files' headers.  Submit under only one name. Also, you can opt to demo your project rather than submit it.  Contact your instructor to set up a time before the due date/time to go to their office and show them, with pride and panache, how wonderful your program works.  If you do this, leave the output statements in so that you can see what is happening all along the way during the simulation.  IF YOU SUBMIT, COMMENT OUT the output statements #2 and #5 above.  This will cut down on the paper produced.  

THE PEOPLE:
Create a file with a .dat or .txt extension that contains the following information in this format:
Homer, -1
Lenny, -1
Milhouse, 1
Bart, 1
Edna Krabappel, -1
Otto Mann, 1
Ned Flanders, 1
Rod Flanders, 1
Marge, -1
Krusty, -1
Disco Stu, 1
Dolph, 1
Dr. Hibbert, -1
Barney, -1
Rev. Lovejoy, -1
Martin, 1
Smithers, 1
Groundskeeper Willie, -1
Ralph Wiggum, 1
Apu Nahasapeemapetilon, -1

Create the file by typing in the information; don't try to copy-n-paste. 

STUFF TO BUY/SELL/PURCHASE/POCKET/THROW/STEAL...
for Moe's:                                                for Comic Book Guy's
4.00    beer                                             4.00 comic book1
10.00 barstool                                         8.00 comic book2
6.00 shot of whiskey                                10.00 comic book3
100.00 complete floor                               10.00 action figure
0.10 peanut                                             20.00 40-sided die
1.00 pickled egg                                      15.00 cheeto value-pak 
20.00 dartgun                                          100.00 limited release RadioMan #1