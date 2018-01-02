// Programmer: Peter Banko          date : 10-7-2013
// Class and Section: Cs53 Section B
// purpose: to revamp Moe's Slots using Function and Structure

#include "slot.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  // Declarations
  bool quit = false; // this is used to quit the program
  int choice; // this is the user input
   
  srand(time(NULL));
  balance y; // Initial user Balance
  
  y.m_Bankk = (rand()%801)+200; // initial Bankk Balance
  y.m_Game = 0; // initial Game balance
  
  do
  {
    Menu();
    cout << endl;
    cout << "Please seclect option listed above: ";
    cin >> choice;
    cout << endl;
    switch(choice)
    {
      case 1:
        dis_bal(y);
        cout << endl;
        do
        {
          Menu();
          cout << endl;
          cout << "Please seclect option listed above: ";
          cin >> choice;
          cout << endl;
          switch(choice)
          {
            case 1:
              dis_bal(y);
              cout << endl;
              break;
            case 2:
              dis_bal(y);
              cout << endl;
              y = transfer(y);
                do
                {
                  Menu();
                  cout << endl;
                  cout << "Please seclect option listed above: ";
                  cin >> choice;
                  cout << endl;
                  switch(choice)
                  {
                    case 1:
                      dis_bal(y);
                      cout << endl;
                      break;
                    case 2:
                      dis_bal(y);
                      cout << endl;
                      y = transfer(y); 
                      break;
                    case 3:
                      y = Play(y);
                      cout << endl;
                      break;
                    case 4:
                      dis_bal(y);
                      cout << endl;
                      quit = true;
                      break;
                    default:
                      cout << "ERROR: Invalid Input" << endl;
                      cout << endl;
                  }
                }while(!quit);
              break;
            case 3:
              cout << "You must transfer funds before playing" << endl;
              cout << endl;
              break;
            case 4:
              dis_bal(y);
              quit = true;
              break;
            default:
              cout << "ERROR: Invalid Input" << endl;
              cout << endl;
          }
        }while(!quit);
        break;
      case 2:
      case 3:
        cout << "You must check your balance before continuing" << endl;
        cout << endl;
        break;
      case 4:
        dis_bal(y);
        quit = true;
        break;
      default:
        cout << "ERROR: Invalid Input" << endl;
        cout << endl;
    }
  }while(!quit);
  return 0;
}
