# Imports needed to run
import argparse
from decimal import *
from random import randint
import time
from datetime import timedelta


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
            GRID[j].append({'info': ' ', 'up': 0, 'right': 0, 'down': 0, 'left': 0})
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
    nPos = 0, 0
    GRID[cPos[0]][cPos[1]]['info'] = 'C'

    alpha = 0.1
    gamma = 0.1
    lastMove = {"coord": (0, 0), "direction": "none"}

    start_time = time.time()
    for step in range(0, args.a):
        # Handle Tiles Falling
        tileFall = randint(0, 1)
        if(tileFall == 1):
            if(lastMove["coord"] != (0, 0)):
                if(cPos in TILES):
                    GRID[lastMove['coord'][0]][lastMove['coord'][1]][lastMove['direction']] -= 10
        
        # Handle Donut Falling
        if(len(activeDonuts) == 0):
            newDonut = randint(0, 3)
            if(newDonut == 0):
                whichDonut = DONUTS[randint(0, 3)]
                activeDonuts.append(whichDonut)
                GRID[whichDonut[0]][whichDonut[1]]["info"] = "D"

        # Find Best Move
        rewardsHere = {"up": 0, "right": 0, "down": 0, "left": 0}
        rewardsHere["up"] = GRID[cPos[0]][cPos[1]]["up"]
        rewardsHere["right"] = GRID[cPos[0]][cPos[1]]["right"]
        rewardsHere["down"] = GRID[cPos[0]][cPos[1]]["down"]
        rewardsHere["left"] = GRID[cPos[0]][cPos[1]]["left"]
        sortedRewardsHere = sorted(rewardsHere.items(), key=lambda x: x[1], reverse=True)
        bestHere = sortedRewardsHere[0]
        
        # Make a Move
        s = randint(1,100)
        weWent = {"from": cPos, "going": "nowhere", "with": bestHere[1]}
        if(s in range(1, 83)):
            weWent["going"] = bestHere[0]
        else:
            notFound = True
            while(notFound):
                choice = randint(0, 3)
                if(MOVES[choice] != bestHere[0]):
                    notFound = False
                    weWent["going"] = MOVES[choice]
        lastMove["coord"] = weWent["from"]
        lastMove["direction"] = weWent["going"]
        rew = 0
        if(weWent["going"] == "up"):
            moveUp = cPos[0]-1, cPos[1]
            if(GRID[moveUp[0]][moveUp[1]]["info"] == "W"):
                rew = -1
            else:
                cPos = moveUp
                if(GRID[cPos[0]][cPos[1]]["info"] == "D"):
                    rew = 10
                    GRID[cPos[0]][cPos[1]]["info"] = " "
                    activeDonuts.pop()
        if(weWent["going"] == "right"):
            moveRight = cPos[0], cPos[1]+1
            if(GRID[moveRight[0]][moveRight[1]]["info"] == "W"):
                rew = -1
            else:
                cPos = moveRight
                if(GRID[cPos[0]][cPos[1]]["info"] == "D"):
                    rew = 10
                    GRID[cPos[0]][cPos[1]]["info"] = " "
                    activeDonuts.pop()
        if(weWent["going"] == "down"):
            moveDown = cPos[0]+1, cPos[1]
            if(GRID[moveDown[0]][moveDown[1]]["info"] == "W"):
                rew = -1
            else:
                cPos = moveDown
                if(GRID[cPos[0]][cPos[1]]["info"] == "D"):
                    rew = 10
                    GRID[cPos[0]][cPos[1]]["info"] = " "
                    activeDonuts.pop()
        if(weWent["going"] == "left"):
            moveLeft = cPos[0], cPos[1]-1
            if(GRID[moveLeft[0]][moveLeft[1]]["info"] == "W"):
                rew = -1
            else:
                cPos = moveLeft
                if(GRID[cPos[0]][cPos[1]]["info"] == "D"):
                    rew = 10
                    GRID[cPos[0]][cPos[1]]["info"] = " "
                    activeDonuts.pop()
        
        rewardsTo = {"up": 0, "right": 0, "down": 0, "left": 0}
        rewardsTo["up"] = GRID[cPos[0]][cPos[1]]["up"]
        rewardsTo["right"] = GRID[cPos[0]][cPos[1]]["right"]
        rewardsTo["down"] = GRID[cPos[0]][cPos[1]]["down"]
        rewardsTo["left"] = GRID[cPos[0]][cPos[1]]["left"]

        sortedRewardsTo = sorted(rewardsTo.items(), key=lambda x: x[1], reverse=True)
        bestTo = sortedRewardsTo[0]
        diff = bestTo[1] - GRID[weWent["from"][0]][weWent["from"][1]][weWent["going"]]
        
        GRID[weWent["from"][0]][weWent["from"][1]][weWent["going"]] += (alpha * (rew + (gamma * diff)))
        

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
    print("Policy Table")
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