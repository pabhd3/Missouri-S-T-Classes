// Programmer: Peter Banko          date: 10-15-2013
// Class and Section: Cs53 Section B
// purpose: to make a dart game for Moe

#include "dart.h"
#include <iostream>
using namespace std;

int main()
{ 
  // Declarations
  bool quit = false;
  int beer;
  char redo; // used to play again
  
  const int MIN = 3; // minimum beers
  const int MAX = 16; // maximum beers
  
  
  
  float X[SHOTS], Y[SHOTS], Score[SHOTS]; // X-coord, Y-coord, distance
  
  string Sound[] = {"ding ding ding!","buuurp!","Hey hey!","Hmmmmm!","DOH!"};
  
  // Program
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  
  do
  {
    beer = get_beer();  
  
    if(beer < MIN)
    {
      display(beer);
    }
    
    else if(beer >= MIN && beer <= MAX)
    {
      play(X, Y, Score, beer);
      dis(X, Y, Score, beer, Sound);
    }
    
    else
    {
      play(Score);
      dis(Score, beer);
    }
    
    cout << "Play Again (y/n): ";
    cin >> redo;
  
    switch(redo)
    {
      case 'Y':
      case 'y':
        break;
      case 'N':
      case 'n':
        quit = true;
        break;
      default:
        cout << "error" << endl;
    }
  }while(!quit);
  return 0;
}

