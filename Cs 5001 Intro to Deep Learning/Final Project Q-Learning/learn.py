# Imports needed to run
import argparse
from random import randint

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
        print("Actions: " + str(args.a))
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


    # Get a Starting Position
    startPoint = True
    xStart = 0; yStart = 0
    while(startPoint):
        xStart = randint(0, 9); yStart = randint(0, 9)
        if(GRID[xStart][yStart]['info'] != 'W'):
            startPoint = False
    cPos = xStart, yStart
    GRID[cPos[0]][cPos[1]]['info'] = 'C'

    for i in range(0,10):
        for j in range(0,10):
            print(GRID[i][j]['info'], end=' ')
        print('\n')

    rewards = {"up": 0, "right": 0, "down": 0, "left": 0}
    alpha = 0.1
    gamma = 0.1
    lastMove = {"coord": (0, 0), "direction": "none"}

    for step in range(0, args.a):
        # Handle Tiles
        tileFall = randint(0, 1)
        if(tileFall == 1):
            print("Tiles Fell!")
            if(lastMove["coord"] != (0, 0)):
                if(cPos in TILES):
                    print("We were hit!")
                    GRID[lastMove["coord"][0]][lastMove["coord"][1]][lastMove["direction"]] -= 10
        
        # Handle Donuts
        if(len(activeDonuts) == 0):
            whichDonut = DONUTS[randint(0, 3)]
            print("Donut Fell at " + str(whichDonut))
            activeDonuts.append(whichDonut)
            GRID[whichDonut[0]][whichDonut[1]]["info"] = "D"

        # Show Output
        print("Current Position:", str(cPos))
        print("Move Options:    ", GRID[cPos[0]][cPos[1]])
        print("\n")

if __name__ == '__main__':
    main()