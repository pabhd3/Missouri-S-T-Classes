Instructions
For this assignment, you will submit multiple files containing a program written in C++.

Background
Moe has been pleased with your work so far. However, Moe has been losing money on his slot machine and now wants you to re-implement it. This time, you are to use functions. Furthermore, you are to make the machine work in Moe's favor! As you are well aware, Moe has had his run-ins with the law. So, he wants you to make the machine pay him enough that he can afford to pay off the cops on a regular basis.

Specifications
Your program is to fill the requirements of homework #4 along with the optionals of multiple spins and displaying letters, but this time using functions and multiple files. You are to put your function prototypes, constant declarations, and structures in a header ( .h) file, and the implementations of the functions in a implementation ( .cpp) file. Main will be in its own file. So, you should have 3 files in all. You are to decide how to apply "functionalizification" for this assignment. You will be graded on how effectively you do this. Use functions to avoid repeated code, clean up your main, and increase the efficiency of your coding.

Additional Requirements
You are to include a function in your program that will put the outcome of the game definitely in Moe's favor. This function will not be called explicitly by the user of the program; it will be called when the user (player) wins too much. The function is to work like this: If, after the fifth spin, the player has a net gain before any subsequent spin, he will have a forced loss.

So what does this mean? First, the first five spins are off-limits to Moe; they're fair. But after that, before every spin, a net gain by the player will trigger the invocation of the function which will force a losing spin. How you implement this will be graded. If you are good, it'll look random. If you are not careful, then the outcome could look like this:


		aab	win $1
		bbb	win $30
		aba	win $1
		bca	lose $5
		abc	lose $5		net gain so far: $22
		cab	lose $5		function kicks in; still up $17
		cab	lose $5		again, still up $12
		cab	lose $5		again, still up $7
		 .
		 .
		 .
You see what's happening here? It's obviously cheating. Can YOU do better?

When you submit
    * choose option 3
    * choose option 1
    * choose option 2 and transfer $200
    * choose option 3 and spin 30 times
    * cash out