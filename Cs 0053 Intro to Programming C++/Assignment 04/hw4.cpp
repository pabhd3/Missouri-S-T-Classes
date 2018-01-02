// Programmer: Peter Banko                 date: 9-12-13
// Class and Section: Cs53 Section B
// Purpose: This program will run Moe's Slot machine in his Bar


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  // Dececlarations
  bool quit = false;     // used to leave the slot machine
  int choice;            // input of choice 1,2,3, or 4
  int transfer; // amount to tranfer from Bankk
  const string Welcome = "Welcome to Moe's, please select and option below";
  const string Menu_1 = "     OPTIONS     ";
  const string Menu_2 = "    ---------    ";
  const string Menu_3 = "1. Check Bankk Balance";
  const string Menu_4 = "2. Transfer funds to game";
  const string Menu_5 = "3. Play";
  const string Menu_6 = "4. Leave";
  const string Bankk_bal = "Your current Bankk Balance is $";
  const string Game_bal = "Your current Game Balance is $";
  const string Error = "ERROR: Invalid input";   
  const string Transfer_prompt = "Please enter an amount to transfer $";
  
  // Program
  srand(time(NULL));
  int Balance_Bankk = (rand()%800)+200;
  int Balance_Game = 0;
  do
  {
    cout << Welcome << endl;
    cout << Menu_1 << endl;
    cout << Menu_2 << endl;
    cout << Menu_3 << endl;
    cout << Menu_4 << endl;
    cout << Menu_5 << endl;
    cout << Menu_6 << endl;
    cin >> choice;
    switch(choice)
    {
      case 1:
        cout << Bankk_bal << Balance_Bankk << endl;
        cout << Game_bal << Balance_Game << endl;
        do
        {
          cout << Welcome << endl;
          cout << Menu_1 << endl;
          cout << Menu_2 << endl;
          cout << Menu_3 << endl;
          cout << Menu_4 << endl;
          cout << Menu_5 << endl;
          cout << Menu_6 << endl;
          cin >> choice;
          switch(choice)
          {
            case 1:
              cout << Bankk_bal << Balance_Bankk << endl;
              cout << Game_bal << Balance_Game << endl;
              break;
            case 2:
              cout << Bankk_bal << Balance_Bankk << endl;
              cout << Transfer_prompt;
              cin >> transfer;
              if(transfer <= Balance_Bankk && transfer >= 0)
              {
                Balance_Game = Balance_Game + transfer;
                Balance_Bankk = Balance_Bankk - transfer;
                cout << Bankk_bal << Balance_Bankk << endl;
                cout << Game_bal << Balance_Game << endl;
                do
                {
                  int slot_a = (rand()%3)+1;
                  int slot_b = (rand()%3)+1;
                  int slot_c = (rand()%3)+1;
                  cout << Welcome << endl;
                  cout << Menu_1 << endl;
                  cout << Menu_2 << endl;
                  cout << Menu_3 << endl;
                  cout << Menu_4 << endl;
                  cout << Menu_5 << endl;
                  cout << Menu_6 << endl;
                  cin >> choice;
                  switch(choice)
                  {
                    case 1:
                      cout << Bankk_bal << Balance_Bankk << endl;
                      cout << Game_bal << Balance_Game << endl;
                      break;
                    case 2:
                      cout << Transfer_prompt;
                      cin >> transfer;
                      if(transfer <= Balance_Bankk && transfer >= 0)
                      {
                        Balance_Game = Balance_Game + transfer;
                        Balance_Bankk = Balance_Bankk - transfer;
                        cout << Bankk_bal << Balance_Bankk << endl;
                        cout << Game_bal << Balance_Game << endl;
                      }
                      break;
                    case 3:
                      if(Balance_Game >= 5)
                      {
                        cout << "     SLOTS     " << endl;
                        cout << slot_a << slot_b << slot_c << endl;
                        if(slot_a == slot_b && slot_b == slot_c)
                        {
                          cout << "All three slots matched!" << endl;
                          Balance_Game+= 30;
                          cout << Bankk_bal << Balance_Bankk << endl;
                          cout << Game_bal << Balance_Game << endl;
                        }
                        else if(slot_a == slot_b || slot_a == slot_c)
                        {
                          cout << "You had a match!" << endl;
                          Balance_Game++;
                          cout << Bankk_bal << Balance_Bankk << endl;
                          cout << Game_bal << Balance_Game << endl;
                        }
                        else if(slot_b == slot_c)
                        {
                          cout << "You had a match!" << endl;
                          Balance_Game++;
                          cout << Bankk_bal << Balance_Bankk << endl;
                          cout << Game_bal << Balance_Game << endl;
                        }
                        else
                        {
                          cout << "No matches" << endl;
                          Balance_Game-= 5;
                          cout << Bankk_bal << Balance_Bankk << endl;
                          cout << Game_bal << Balance_Game << endl;
                        }
                      }
                      else
                        cout << "ERROR: Insufficient funds" << endl;
                      break;
                    case 4:
                      cout << Bankk_bal << Balance_Bankk << endl;
                      cout << Game_bal << Balance_Game << endl;
                      quit = true;
                      break;
                    default:
                      cout << Error << endl;
                  }
                }while(!quit);
              }
              else
                cout << "ERROR: Insufficient funds" << endl;
              break;
            case 3:
              cout << "You must transfer funds before you can play" << endl;
              break;
            case 4:
              cout << Bankk_bal << Balance_Bankk << endl;
              cout << Game_bal << Balance_Game << endl;
              quit = true;
              break;
            default:
              cout << Error << endl;
              break;
          }
        }while(!quit);
        break;
      case 2:
      case 3:
        cout << "You must check your Bankk Balance before continuing" << endl; 
        break;
      case 4:
        cout << Bankk_bal << Balance_Bankk << endl;
        cout << Game_bal << Balance_Game << endl;
        quit = true;
        break;
      default:
        cout << Error << endl;
        break;
    }
  }while(!quit);
  return 0;
}
