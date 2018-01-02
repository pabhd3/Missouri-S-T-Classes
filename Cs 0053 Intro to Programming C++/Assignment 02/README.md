Instructions
For this assignment, you will submit a single C++ compilable file containing a program written in C++. 

Background
One of the more entrepreneurial of the citizenry of your town, let's call it Springfield, wishes to hire you, an aspiring young programmer, to write a program for him.  His name is Moe Sizlack, and he will be commissioning you to write software for him all semester long.  In the present, Moe wants you to write a  program to generate phone numbers for his patrons at the bar (Moe's Bar).  He just isn't making enough money to suit his life style, so he figures he can create a "start up" phone business, selling subscriptions to his bar patrons.  The idea has the added benefit that he can forward to those patrons the prank phone calls he gets at the bar that drive him crazy.  Then, when the patrons get crazy about the pranks, he can charge them to stop the forwards!  Nice plan, Moe.

His patrons will also eventually be able to buy a moe-phone.

Specifications
The numbers you will generate will be based on inputs from the user, the patrons.  That's right, the patrons get to input information that will determine their phone number.  That information is: 
* the wavelength of their eye color
* their height in meters
* their gender (male or female)

The program is to begin by prompting for the person's first and last names. It should then use their name in prompts for the person's eye color, gender, and then the person's height.  

Use the following requirements/information:

* hoices for eye color will be blue (475 nm), green (510 nm), orange (590 nm). Your prompt for color should include these choices, but it should simply read in an integer. We will assume that the user will enter one of these numbers. Your prompt should look something like:
                Please enter eye color (475 for blue, 510 for green, 590 for orange): __
* For gender, prompt 0 for male and 1 for female, and read user input into an integer variable.
* Prompt for and read the height into a floating point type variable.

The phone number  abc - def - hijk  is to be built as follows:

* abc is simply the wavelength of the color of their eyes.  I know this is stupid, most of what follows is also.
* def is the last three digits of the integer part of the product of their height (meters) times their (eye color) wavelength.  If their height is less than .21, they don't get a phone number since this product won't be at least 100.  But, that means they are only about 7 inches tall; what are they going to do with a phone?
* hijk is:  (10 * wavelength) + (PNGF * gender) + height2
where PNGF is the Phone Number Gender Factor currently set at 78 by Congressional House Bill HB-473957.78463a

Once you have determined the proper phone number, output the information appropriately. This means "user friendly" output. This excludes simple output like:
        123-758-6465

Notice that there is no name, no label on the number, etc. Your output should look NICE like:
                Name:                         Krusty Clown
                Phone Number:         123-758-6465
                My Motto:                 "Get a phone, Buy a beer!"
Reminder
When writing your code, be sure to:

* Use meaningful variable names.
* Use proper spacing for indentations.
* Use constant variable declarations where appropriate.
* Include the comment block at the head of your file.
* Comment code that needs it.
* Be literate in your welcoming/signing-off messages and prompts and output.

Submitting
The submit script will (attempt to) compile and execute your program in the process. This means that you will be the "user" of the program for that few minutes. Now, in order that the grader isn't driven crazy by a multitude of inputs/outputs, you will ALL input the same values so that he has uniform output to grade. They are:

* your own personal name info
* choose 590 for wavelength
* choose male
* height of 1.78 m

Be sure to test your program (with a calculator!).
As always, if you have questions, don't hesitate to ask your instructor or the tutor in the lab in the evenings.