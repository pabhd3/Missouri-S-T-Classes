// Programmer: Peter Banko         date: 11-3-2013
// Class and Section: Cs53 Section B
// purpose: to wite stories for Moe

#include "story.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  // Declarations
  char first;
  char choice;
  bool quit=true;
    
  // Program
  cout << "So Moe, are you ready to make a fable? (y/n): ";
  cin >> first;
  
  ofstream fout("MoeFables.txt");
  
  srand(time(NULL));
  
  switch(first)
  {
    case 'y':
    case 'Y':
    {
      do
      {
        int Fab = rand()%5;
        
        switch(Fab)
        {
          case 0:
          {
            ifstream f1in("fable1.txt");
            cout << endl;
            Bulk(f1in, fout);
            f1in.close();            
          }
          case 1:
          {
            ifstream f2in("fable2.txt");
            cout << endl;
            Bulk(f2in, fout);
            f2in.close();
          }
          case 2:
          {
            ifstream f3in("fable3.txt");
            cout << endl;
            Bulk(f3in, fout);
            f3in.close();
          }
          case 3:
          {
            ifstream f4in("fable4.txt");
            cout << endl;
            Bulk(f4in, fout);
            f4in.close();
          }
          case 4:
          {
            ifstream f5in("fable5.txt");
            cout << endl;
            Bulk(f5in, fout);
            f5in.close();
          }
        }
        cout << "So Moe, do you want to write a fable? (y/n): ";
        cin >> choice;
        switch(choice)
        {
          case 'y':
          case 'Y':
            break;
          case 'n':
          case 'N':
          {
            quit = false;
            fout.close();
            break;
          }
        }
      }while(!quit);
    }
    case 'n':
    case 'N':
    {
      fout.close();
      break;
    }
  }
  fout.close();
  return 0;
}
