Problem:
Tinny Tim, the little orphan robot, lives in an abandoned basement in New New York City.  Tinny Tim's basement can be described as a 10x10 grid.
Occasionally, a donut may fall from the street above into one of the corners of the basement (marked with 'D' in the map below). When Tinny Tim lands on a corner with a donut, it receives a reward of 10 and the donut disappears. When there is no donut in any of the corners, each time step there is a probability of 0.25 that a new donut may drop on any one of the corners with equal likelihood. 
The basement is also a dangerous place. Tiles can drop from the roof at any time step with probability 0.50 on each of the locations marked 'T'.  Tinny Tim gets damaged if a tile falls on the square he is on. If Tinny Tim gets hit by a tile, he receives a punishment of −10. 
Tinny Tim can perform four actions: up, down, left, and right. These actions will usually ( 82% of the time ) move Tinny Tim in the direction indicated by the action's name, but sometimes, with equal likelihood, in one of the other directions.   If Tinny Tim crashes into an outside wall or one of the interior walls, it remains where is was and receives a reward of −1.

-----------------------------------------------------------------------------------

Map of Basement:
W - Wall   D - Donut   T - Tile

W W W W W W W W W W
W D   T         D W
W   W   W W W T   W
W   W             W
W   W       W     W
W   T       W     W
W       W T W     W
W   T   W         W
W D     W       D W
W W W W W W W W W W

-----------------------------------------------------------------------------------

Reinforcement Learning:
You shall implement a reinforcement learning algorithm, either Q-Learning or SARSA, and compute the optimal policy Tinny Tin should follow to maximize the reward of living in his squalid basement.