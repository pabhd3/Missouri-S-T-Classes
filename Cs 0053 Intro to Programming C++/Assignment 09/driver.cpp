// Programmer: Peter Banko          date: 11-11-2013
// Class and Section: Cs53 Section B
// purpose: to practice OOP, to be used in hw10

#include "customer.h"
#include <iostream>
using namespace std;

int main()
{
  // Declarations    
  customer F;
  customer G("Steven",100);  
  
  // Driver
  cout << "Print Function" << endl;
  F.print();  
  G.print();
  cout << endl;
  
  cout << "Name Accessor" << endl;
  cout << F.getName() << endl;   
  cout << G.getName() << endl;
  cout << endl;
  
  cout << "Money Accessor" << endl;
  cout << F.getMny() << endl;
  cout << G.getMny() << endl;
  cout << endl;
  
  cout << "Money Mutator" << endl;
  F.setMny(50);
  cout << F.getMny() << endl;
  G.setMny(50);
  cout << G.getMny() << endl;
  cout << endl;
  
  return 0;
}

