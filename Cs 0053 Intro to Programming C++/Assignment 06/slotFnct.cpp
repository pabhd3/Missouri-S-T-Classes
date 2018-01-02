// Programmer: Peter Banko    date: 10-10-2013
// Class and Section: Cs53 Section B
// purpose: to revamp Moe's slot machine using structs and functions

#include "slot.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Menu()
{ 
  cout << "-----Menu-----" << endl;
  cout << endl;
  cout << "1. Check Balance" << endl;
  cout << "2. Transfer Funds" << endl;
  cout << "3. Play Slots" << endl;
  cout << "4. Quit" << endl;
  return;
}

void dis_bal(balance x)
{
  cout << "Your Bankk Balance is currently $";
  cout << x.m_Bankk << endl;
  cout << "Your Game Balance is currently $";
  cout << x.m_Game << endl;
  return;
}

char print_slot(int X)
{
  char Y; // returned character
  
  switch(X)
  {
    case 1:
      Y = 'A';
      break;
    case 2:
      Y = 'B';
      break;
    case 3:
      Y = 'C';
      break;
  }
  return Y;
}

balance Play(balance x)
{
  srand(time(NULL));
  
  int spin_ct; // user chosen number of spins
  
  int const LOSE = 5;
  int const MATCH = 1;
  int const WIN = 30;
    
  cout << "Number of spins: ";
  cin >> spin_ct;
  cout << endl;
  
  if(spin_ct < 0 || (spin_ct * 5) > x.m_Game)
    cout << "ERROR" << endl;
  else
  {
    for(int i=0; i < spin_ct; i++)
    {  
      int slot_a = (rand()%3)+1;
      char outA = print_slot(slot_a);
      
      int slot_b = (rand()%3)+1;
      char outB = print_slot(slot_b);
      
      int slot_c = (rand()%3)+1;
      char outC = print_slot(slot_c);
      
      int cht = (rand()%5)+1; // used for a forced loss
      
      int loss_a, loss_b, loss_c;
      
      if(cht == 1 || cht == 3) // 40-percent chance of forced loss
      {
        do
        {
          loss_a = (rand()%3)+1;
          loss_b = (rand()%3)+1;
          loss_c = (rand()%3)+1;
        }while(loss_a == loss_b || loss_b == loss_c || loss_a == loss_c);
        
        char putA = print_slot(loss_a);
        char putB = print_slot(loss_b);
        char putC = print_slot(loss_c);
        
        x.m_Game-= LOSE;
        cout << putA << " " << putB << " " << putC;
        cout << "     You lost $5" << endl;
      }
      else
      {
        cout << outA << " " << outB << " " << outC;
        if(slot_a == slot_b && slot_b == slot_c)
        {
          x.m_Game+= WIN;
          cout << "     You won $30" << endl;
        }
        else if(slot_a == slot_b || slot_b == slot_c)
        {
          x.m_Game+= MATCH;
          cout << "     You won $1" << endl;
        }
        else if(slot_a == slot_c)
        {
          x.m_Game+= MATCH;
          cout << "     You won $1" << endl;
        }
        else
        {
          x.m_Game-= LOSE;
          cout << "     You lost $5" << endl;
        }
      }
    }
  }
  cout << "Game now has a balance of $" << x.m_Game << endl;
  cout << endl;
  return x;
}

balance transfer(balance x)
{
  int tran;
  cout << "Enter amount to transfer to game $";
  cin >> tran;
  if(tran <= x.m_Bankk && tran >=0)
  {
    x.m_Bankk-= tran;
    x.m_Game+= tran;
    cout << "Bankk now has a balance of $" << x.m_Bankk << endl;
    cout << "Game now has a balance of $" << x.m_Game << endl;
    cout << endl;
  }
  else
  {
    cout << "ERROR" << endl;
    cout << endl; 
  }
  return x;
}
