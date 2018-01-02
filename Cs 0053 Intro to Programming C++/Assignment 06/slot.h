// Programmer: Peter Banko     date: 10-10-2013
// Class and Section: Cs53 Section B
// purpose: to revamp Moe's slots using function and structure

#ifndef SLOT_H
#define SLOT_H

#include <iostream>
using namespace std;

struct balance // This structure hold the Balance of the player
{
  int m_Bankk;
  int m_Game;
};

// This funtion will output a menu with available choices to user
// Pre: none
// Post: a menu is output
void Menu();

// This function will display the Bankk and Game balance of current user
// Pre:
// Post: a Bankk balance and Game balance are output
void dis_bal(balance x);

// This function will allow the user to spend their game balance in the actual
//   slots game, to try to earn more money
// Pre: The user's Balance is taken to be adjusted
// Post: the user's adjusted balance is returned
balance Play(balance x);

// This function will transfer funds from the Bankk to the Game
// Pre: The user's Balance is taken to be adjusted
// Post: the user's adjusted Bankk and Game balance are returned
balance transfer(balance x);

// This function will take a random number generated, and convert it to
//   either A, B, or C
// Pre: a randomly generated integer is taken in
// Post: the char 'A', 'B', or 'C' is returned
char print_slot(int X);

#endif
