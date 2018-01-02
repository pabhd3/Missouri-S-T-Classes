Instructions
For this assignment, you will submit multiple files containing a program written in C++. You know the rest.

Background
Moe, always seeking to get ahead in life, wants to put a dark game in his bar.  But knowing how dangerous drunks throwing sharp projectiles can be, he decides replacing the free-throw-darts with a shotgun converted to shoot darts is wiser (remember, Moe is not too bright).  And since "Snake" (pictured to the right with mullet) would almost certainly use the gun to hold up the bar, Moe mounts the gun at a fixed height and also in a way that it can't be aimed at the bartender.  He puts a target on the wall.  It's not an ordinary dartboard target (that would be too simple and not nearly as interesting as the nonsense you're about to have to deal with). The target consists of a set of concentric rings, each with a sensor that detects a hit, which will then trigger a "sound".  Players of the game must divulge how many beers they have consumed prior to playing.  This input will determine how the game will treat them.

Specifications
The program you write will simulate the game.  Your program is to allow patrons to play the game as many times as they wish.  The game will first prompt/readin the number of beers the patron has consumed.  If that is less than the minimum number of beers Moe requires for playing (currently set at 2), then Moe will not allow the patron to shoot, and instead gives that patron a score equal to the integer part 1/2 times the number of beers they consumed.  If that number is at least the minimum but no greater than the maximum Moe allows (currently set at 12), then the patron is allowed to play, which consists of 10 shots with the dart gun.  For each shot, the score for that shot is the distance from the bull's eye. Thus the score for a round at the game is based on the 10 distances.  And in this case, the patron is given two scores:  one regular score, and one "handicapped" score.  These scores are described below.  Finally, if the patron's beer consumption exceeds the maximum allowed, then they can "play", but your code will generate and record the scores (distances) of the 10 shots randomly for the patron while they're stumbling around the bar drunk looking for the dart gun.  They don't actually shoot the dart gun, but they end up with a score determined the same way as if they had indeed shot.  After the score for the round is calculated and presented to the patron, they are asked if they want to "go again".

Scoring

There are three ways to compute the score for a round.  They are:
    1. for less than the minimum required beers:  score = integer part of 1/2 × beers
    2. for beers between min and max (inclusive):  handicap score = (1/n) × Σ (û - ui)2,  
        where ui is the distance for the ith shot, 
            û is the average of the n shot distances, 
            n is the number of shots, and 
            the sum is over the n shots.
    3. for beers between min and max (inclusive):  regular score = û / beers

he Play
When a player shoots the dart gun, your code will determine where the dart lands on the wall, which is 11 feet away, according to the following formulas:

x = 11 × sin(γ) / cos(γ)
y = 11 × sin(θ) / cos(θ)cos(γ)

You may take x and y as coordinates in the 2-D plane of the wall where the origin (or center) is the point directly in front of the dart gun.  Notice that these formulas assume a flat trajectory. And notice that both x and y depend on the two angles, θ (the angle of elevation off of the horizontal) and γ (the angle left or right of straight ahead).  These values (integers) will be determined by your code randomly (of course) in the interval [(-2 × beers)°, (+2 × beers)°].  For example, if the patron had consumed 5 beers, then each of the angles are chosen randomly between -10° and 10°. This simulates wilder shooting as the number of beers increases.  Your code will then have to compute the distance1 from the landing point of the dart to the bull's-eye or origin, which is the point straight in front of the gun at the same height.  [Hint:  Remember that, though your angles are in degrees, all scientific computations are done in radians.  So, once you randomly pick an angle in degrees, you must multiple by π / 180 = 3.14159/180 = 0.017453 to change it to radians.  That will be the value you use in the formulas above.]

In addition to the above, the target is very special indeed.  It is a comprised of concentric rings one foot wide.  Each ring is covered with sensors that emit a particular sound when hit.  The first (inner most) ring would sense any shot at most 1 foot from center and it emits the sound "ding ding ding!".  The second ring senses hits greater than 1 foot but less than or equal to 2 feet from center, and it's sound is Barney's sound, "buuurrrrppp!"  Third is Krusty's favorite screach, "Hey hey!"  Fourth emits Marge's untterance, "Hmmmmmmm!"  The fifth ring registers hits greater than 4 feet from the center and screams "DOH!"  These sounds should be output when a hit registers in their ring.  This, of course, applies only in the case that the patron actually shoots for a play of the game.  The output might look like                      

x = 3.2, y = 1.2      score = 3.4      Hmmmmmm! 
x = 1.1, y = 0.9      score = 1.4      buuuuuuuurrrrpp!

Of course, if they don't actually throw the darts (as is the case if they've had too many beers and Moe makes up their scores), the sounds don't happen.

The Code
You will use arrays to hold the data.  You will use functions fully.   You will want to use cmath for the built-in functions sin(x) and cos(x) and sqrt(x).  (They take a double and return a double or anything that can be promoted to a double.) You will overload the score function three ways, and the play function 2 ways.  You might consider the following pseudo-code for the core of your main function:          

get beers

    if beers < min

        present score(beers)

    else if beers <=max

        play(array_of_sounds,array_of_scores,beers)

        present score(array_of_scores,beers)  //regular score

        present score(array_of_scores)        //handicap score

    else 

        play(array_of_scores)

        present score(array_of_scores)       //handicap score since they are obviously need it


When you submit
    * play and enter that you have had 2 beers
    * play and enter that you have had 7 beers
    * play and enter that you have had 15 beers
    * stop playing