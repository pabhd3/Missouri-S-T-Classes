Instructions
For this assignment, you will submit a single C++ compilable file containing a program written in C++.

Background
Moe has more business and wants to add a gaming machine to the entrance of the bar. You are going to write the software to run the machine. It's a combination of ATM (automatic teller machine - produces money "magically") and a SLOTS machine (you know, that machine that you pull handle and three tumblers spin and you want the pictures to match).  The one in the picture probably costs $100,000; Moe's was made in his basement and is constructed from old washtubs, duct-tape, baling wire, beer bottles, and spit.  But he figures that if your program is good enough, it won't matter how ugly the machine is.
 
Specifications
Your program, if Moe likes it, will be running on a machine at the front door of Moe's. As patrons enter and make it past the last machine you programmed, they will have the option to play. The machine will present a menu with these choices:
                           OPTIONS
                           --------------
            1.  Check Bankk® balance
            2.  Transfer funds to game
            3.  Play
            4.  Leave (cash out)

A player can "leave" anytime, but he/she/it cannot "play" before transferring any funds to the game, and cannot "transfer" before first checking savings balance. Thus, it should be clear by now, that the first choice any player must make is to check their balance. They must then transfer funds to the game. After this, players are free to make any choice of the menu in any order as long as they have funds to cover their addiction. 

Specs on Specs 
    1. The "Check Bankk balance" option is to display their Bankk balance and the game balance. The game balance will start at $0.00 and will accumulate value as the user transfers funds from the Bankk to the game or as winnings accrue. The initial Bankk balance will be a value randomly chosen (only once) between $200 and $1000, inclusive.  Any subsequent check of the Bankk balance reflects any subtractions from that initial balance. We'll discuss use of the random number generator below and in class.
    2. The "Transfer.." option will allow the user to transfer funds (not to exceed the Bankk balance) to the game balance to be used for gambling.
    3. "Play" allows the user to play the game. The game will randomly produce three integers between 1 and 4, inclusive.  That is, a spin could produce the result 2 3 1, or it could be 4 1 1, or .... You get the idea. Imagine there are three tumblers (as in all these kinds of machines) but the tumblers have only 4 sides with pictures of the digits 1 2 3 and 4. If any two pictures match, the game balance is increased by $1; if all three match, the game balance increases by $30 (remember: Moe is a cheapskate). If none match, then balance decreases by $5. Now, your game must check to see if the game balance for a player can handle the potential loss when they choose to play.
    4. "Leave" will report the amount the player has in the game balance and Bankk balance.

Now remember, if the player has no more funds (anywhere), then they have no choice but to "Leave".

In your code, you are required to use the switch statement for handling menu choices. 

When You Submit
The submit script will (attempt to) compile and execute your program in the process. This means that you will be the "user" of the program for that few minutes. Now, in order that the grader isn't driven crazy by a multitude of inputs/outputs, you will ALL input the same values so that he has uniform output to grade. They are:
* choose option 3
* choose option 1
* choose option 2, transfer $3
* choose option 3
* choose option 2, transfer $30
* choose option 3
* quit

Optional
There are some fun things you can do to modify this program to make it a little more interesting and difficult.  If you would like to try them, go ahead.  Any bonus points assigned for these are up to your instructor.

* for each play, ask the user how many spins he/she wants and act accordingly (including calculations of potential losses).
* display not digits, but letters.  So the results of a spin might be  a b d  or   d d c  or .....

Random Numbers
You should seed the random number generator at the beginning of main using the command srand(time(NULL)); . time(NULL) will seed the generator with the number of seconds elapsed since Jan. 1, 1971, or some such crazy integer. Thus, every second passing would seed the generator with a different value. In order for this to work, you need to include the system file called ctime . In order to get a random number, use the command rand() , which will return a long int. We'll discuss particulars in class.