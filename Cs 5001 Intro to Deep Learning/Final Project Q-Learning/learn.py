# Imports needed to run
import argparse
from decimal import *
from random import randint
import time
from datetime import timedelta

def nextPos(cardinal):
    if(cardinal == "W"):
        return -1
    elif(cardinal == "D"):
        return 10
    else:
        return 0
        

def main():
    # Set up Argparse
    parser = argparse.ArgumentParser(description='Generate a Random Graph')
    parser.add_argument('-a', metavar='Actions', type=int, default=0, 
                        help='Flag sets number of Actions to take (Will go until Converge by default)')
    args = parser.parse_args()

    if (args.a != 0):
        print("Actions: " + "{:,}".format(args.a))
    else:
        print("Until Converge")

    # Build Basement
    GRID = []
    for i in range(0,10):
        GRID.append([])
    for j in range(0,10):
        for k in range(0,10):
            GRID[j].append({'info': ' ', 'up': 10, 'right': 10, 'down': 10, 'left': 10})
    for i in range(0,10):
        GRID[0][i]['info'] = "W"
        GRID[9][i]['info'] = "W"
        GRID[i][0]['info'] = "W"
        GRID[i][9]['info'] = "W"
    GRID[2][2]['info'] = "W"; GRID[3][2]['info'] = "W"; GRID[4][2]['info'] = "W"
    GRID[2][4]['info'] = "W"; GRID[2][5]['info'] = "W"; GRID[2][6]['info'] = "W"
    GRID[6][4]['info'] = "W"; GRID[7][4]['info'] = "W"; GRID[8][4]['info'] = "W"
    GRID[4][6]['info'] = "W"; GRID[5][6]['info'] = "W"; GRID[6][6]['info'] = "W"
    TILES = [(1, 3), (2, 7), (3, 4), (5, 2), (6, 5), (6, 7), (7, 2)]
    DONUTS = [(1, 1), (1, 8), (8, 1), (8, 8)]
    activeDonuts = []
    MOVES = ["up", "right", "down", "left"]


    # Get a Starting Position
    startPoint = True
    xStart = 0; yStart = 0
    while(startPoint):
        xStart = randint(0, 9); yStart = randint(0, 9)
        if(GRID[xStart][yStart]['info'] != 'W'):
            startPoint = False
    cPos = xStart, yStart
    GRID[cPos[0]][cPos[1]]['info'] = 'C'

    #for i in range(0,10):
        #for j in range(0,10):
            #print(GRID[i][j]['info'], end=' ')
        #print('\n')

    alpha = 0.2
    gamma = 0.2
    lastMove = {"coord": (0, 0), "direction": "none"}
    rewards = {"up": 0, "right": 0, "down": 0, "left": 0}

    start_time = time.time()
    for step in range(0, args.a):
        hund = args.a / 100
        if(step % hund == 0):
            print(str(step/hund) + "% Complete")
        #print("Current Position: " + str(cPos))
        # Handle Tiles Falling
        tileFall = randint(0, 1)
        if(tileFall == 1):
            if(lastMove["coord"] != (0, 0)):
                if(cPos in TILES):
                    #print("Ouch! A Tile fell on us at ", cPos, lastMove)
                    #print(GRID[lastMove['coord'][0]][lastMove['coord'][1]][lastMove['direction']])
                    GRID[lastMove['coord'][0]][lastMove['coord'][1]][lastMove['direction']] -= 10
                    #print(GRID[lastMove['coord'][0]][lastMove['coord'][1]][lastMove['direction']])
        
        # Handle Donut Falling
        if(len(activeDonuts) == 0):
            whichDonut = DONUTS[randint(0, 3)]
            activeDonuts.append(whichDonut)
            GRID[whichDonut[0]][whichDonut[1]]["info"] = "D"
            # print("A donut fell at: " + str(whichDonut))

        # Find Best Move
        testup = cPos[0]-1, cPos[1]
        rewards["up"] = nextPos(GRID[testup[0]][testup[1]]['info'])
        testright = cPos[0], cPos[1]+1
        rewards["right"] = nextPos(GRID[testright[0]][testright[1]]['info'])
        testdown = cPos[0]+1, cPos[1]
        rewards["down"] = nextPos(GRID[testdown[0]][testdown[1]]['info'])
        testleft = cPos[0], cPos[1]-1
        rewards["left"] = nextPos(GRID[testleft[0]][testleft[1]]['info'])
        bestReward = max(rewards, key=rewards.get)
        GRID[cPos[0]][cPos[1]]["up"] = GRID[cPos[0]][cPos[1]]["up"] + alpha * (rewards["up"] + gamma * rewards[bestReward] - GRID[cPos[0]][cPos[1]]["up"])
        GRID[cPos[0]][cPos[1]]["right"] = GRID[cPos[0]][cPos[1]]["right"] + alpha * (rewards["right"] + gamma * rewards[bestReward] - GRID[cPos[0]][cPos[1]]["right"])
        GRID[cPos[0]][cPos[1]]["down"] = GRID[cPos[0]][cPos[1]]["down"] + alpha * (rewards["down"] + gamma * rewards[bestReward] - GRID[cPos[0]][cPos[1]]["down"])
        GRID[cPos[0]][cPos[1]]["left"] = GRID[cPos[0]][cPos[1]]["left"] + alpha * (rewards["left"] + gamma * rewards[bestReward] - GRID[cPos[0]][cPos[1]]["left"])
        rewards["up"] = GRID[cPos[0]][cPos[1]]["up"]
        rewards["right"] = GRID[cPos[0]][cPos[1]]["right"]
        rewards["down"] = GRID[cPos[0]][cPos[1]]["down"]
        rewards["left"] = GRID[cPos[0]][cPos[1]]["left"]
        bestMove = max(rewards, key=rewards.get)
        #print(bestMove, GRID[cPos[0]][cPos[1]][bestMove])
        #print("Movement Options: " + str(GRID[cPos[0]][cPos[1]]))
        #print("We want to move:  " + bestReward + " with reward " + str(GRID[cPos[0]][cPos[1]][bestReward]))

        # Make a Move
        stumble = randint(1,100)
        if(stumble in range(1,82)):
            #print("Successfully moved:  " + bestReward + " with reward " + str(GRID[cPos[0]][cPos[1]][bestReward]))
            lastMove["coord"] = cPos
            lastMove["direction"] = bestMove
            print(lastMove)
            if(bestMove == "up"):
                cPos = (cPos[0]-1, cPos[1])
            elif(bestMove == "right"):
                cPos = (cPos[0], cPos[1]+1)
            elif(bestMove == "down"):
                cPos = (cPos[0]+1, cPos[1])
            else:
                cPos = (cPos[0], cPos[1]-1)
            if(cPos in activeDonuts):
                #print("Yay! We ate a Donut!!!")
                activeDonuts.pop()
                GRID[cPos[0]][cPos[1]]["info"] = " "
        else:
            other = True
            while(other):
                otherDir = MOVES[randint(0,3)]
                if(otherDir != bestMove):
                    stumbledTo = cPos
                    if(otherDir == "up"):
                        stumbledTo = (cPos[0]-1, cPos[1])
                    elif(otherDir == "right"):
                        stumbledTo = (cPos[0], cPos[1]+1)
                    elif(otherDir == "down"):
                        stumbledTo = (cPos[0]+1, cPos[1])
                    else:
                        stumbledTo = (cPos[0], cPos[1]-1)
                    if(GRID[stumbledTo[0]][stumbledTo[1]]["info"] != "W"):
                        other = False
            #print("Stumbled:  " + otherDir + " with reward " + str(GRID[stumbledTo[0]][stumbledTo[1]][otherDir]))
            lastMove["coord"] = cPos
            lastMove["direction"] = otherDir
            print(lastMove)
            cPos = stumbledTo
            if(cPos in activeDonuts):
                #print("Yay! We ate a Donut!!!")
                activeDonuts.pop()
                GRID[cPos[0]][cPos[1]]["info"] = " "
        #print("\n")

    end_time = time.time()
    elapsed_time = end_time - start_time

    # Build Policy Table
    p = [[], [], [], [], [], [], [], [], [], []]
    for i in range(0,10):
        for j in range(0,10):
            if(GRID[i][j]["info"] == "W"):
                p[i].append(" ")
            else:
                squareRewards = {"up": GRID[i][j]["up"], "right": GRID[i][j]["right"], "down": GRID[i][j]["down"], "left": GRID[i][j]["left"]}
                p[i].append(max(squareRewards, key=squareRewards.get))
    s = [[str(e) for e in row] for row in p]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print("Rewards Table")
    print('\n'.join(table))
    print("\n")
    # Build Rewards Table
    getcontext().prec = 4
    r = [[], [], [], [], [], [], [], [], [], []]
    for i in range(0,10):
        for j in range(0,10):
            squareRewards = [GRID[i][j]["up"], GRID[i][j]["right"], GRID[i][j]["down"], GRID[i][j]["left"]]
            r[i].append(round(max(squareRewards, key=int), 5))
    s = [[str(e) for e in row] for row in r]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print("Rewards Table")
    print('\n'.join(table))
    print("\nTime Elapsed: " + str(timedelta(seconds=elapsed_time)) + " (Hr:Min:Sec)")


if __name__ == '__main__':
    main()