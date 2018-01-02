// Peter Banko          Cs53
// the "simulator" for the program

#include "customer.h"
#include "business.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
  srand(time(NULL)); 
  
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  // Declarations
  const int START_C = 20; // starting number of customers
  int NumC = START_C;
  int NumRounds = 5; // number of rounds
  
  customer A[START_C]; // customer array
  string blank;
  string pref;
  
  business Moe; // Moe's business
  business CBG; // Comic book Guy's business
  
  Moe.setName("Moe's Bar");
  CBG.setName("Comic Book Guy's");
  
  int count = 0; // round count
  
  // File streams
  ifstream fin("CustomerList.txt");
  
  // Simulator
  
  cout << endl;  
  cout << "Beginning Stats" << endl;
  cout << "----------------------------------------------------------" << endl;
  
  for(int i=0; i < NumC; i++)
  {
    blank = ""; // clears name
    pref = ""; // clears preferance
    
    getline(fin,blank,','); // gets name
    A[i].setName(blank); // sets name
    
    getline(fin,pref,'\n'); // gets peferance
    A[i].setPref(pref); // sets preferance
  }
  fin.close();

  // Finding number of Items offered by each business
  char lineSize[100]; // possibility for long line
  
  int MoeItem = 0;
  int CBGitem = 0;
  
  ifstream xin("MoeItem.txt");
  while(xin.getline(lineSize,100,'\n'))
    MoeItem++;
  xin.close();
  
  Moe.setItemLine(MoeItem);
  
  ifstream lin("CBGitem.txt");
  while(lin.getline(lineSize,100,'\n'))
    CBGitem++;
  lin.close();

  CBG.setItemLine(CBGitem);

  // Filling Inventory for Moe
  ifstream min("MoeItem.txt"); 
  char next;
      
  for(int i=0; i < MoeItem; i++)
  {
    blank = "";
    pref = "";
    
    getline(min,blank,','); // gets product name
    Moe.setPname(blank); // sets name
    
    Moe.StringtoFloat(min);
    min.get(next);
  }
  min.close();
  
  // Filling Inventory for Comic Book Guy
  ifstream pin("CBGitem.txt");
  
  for(int i=0; i < CBGitem; i++)
  {
    blank = "";
    
    getline(pin,blank,',');
    CBG.setPname(blank);
    
    CBG.StringtoFloat(pin);
    pin.get(next);
  }
  
  // Beginning Stats
  for(int i=0; i < NumC; i++)
    cout << A[i] << endl; 
  cout << endl;
    
  int round;
  
  // Outputting Businesses
  cout << endl;
  cout << Moe << endl;
  cout << endl;
  cout << CBG << endl;
      
  while((NumC > 1)&&(count < NumRounds))  
  {
    round = count + 1;
    cout << endl;    
    cout << "Round " << round << endl;
    cout << "----------------------------------------" << endl;
    
    //  Sorting Customers into Business
    string preference;
  
    for(int i=0; i < NumC; i++)
    {
      preference = "";
    
      preference = A[i].getPref();
    
      if(preference == "1")
        Moe.addCustomer(A[i]);
      else
        CBG.addCustomer(A[i]);
    }
   
    // Buying
    cout << "< Purchases >" << endl;
    
    Moe.SellStuff();
    CBG.SellStuff();
    
    // Leaving the Businesses 
    int start=0;
  
    Moe.Leave(A,start);
    CBG.Leave(A,start);
    
    // Updates
//    cout << "< Updates >" << endl;
//    for(int i=0; i < NumC; i++) cout << A[i] << endl;
        
    // Shuffle 
    int swap;
    customer Temp;
  
    for(int i=0; i < NumC; i++)
    {
      swap = rand()%NumC; // choose place to swap
    
      Temp = A[i];
      A[i] = A[swap];
      A[swap] = Temp;   
    }
    // Interaction 
    int interact;
    cout << endl;
    cout << "< Interactions >" << endl;
      
    for(int i=0; i < NumC; i++)
    {
      interact = rand()%NumC;
    
      A[i].Interact(A[interact]);
    }
    cout << endl;
    // Updated Customer stats
    
    cout << "< Updates >" << endl;
    for(int i=0; i < NumC; i++) cout << A[i] << endl;
   
    // Removing Appropriate Customers  
    cout << endl;
    int Cmood;
    int Rem;
    cout << "< Departures >" << endl;
    for(int i=0; i < NumC; i++)
    {
      Cmood = A[i].getMood();
      if((Cmood <= 10) || (Cmood >= 90))
      {
        cout << A[i].getName() << " has left Springfield with happines ";
        if(Cmood < 0)
          cout << "0" << endl;
        else
          cout << A[i].getMood() << endl;
        
        Rem = NumC - 1;
        Temp = A[Rem]; // picks up last customer in array
        A[i] = Temp; // moves the last customer to one removed
        NumC--;
      }
    }
    count++;
  }
  cout << endl;
  cout << "End Results" << endl;
  cout << "--------------------------------" << endl;
  cout << endl;
  
  cout << "< Remaining Customers >" << endl;
  for(int i=0; i < NumC; i++)
    cout << A[i] << endl;
  cout << endl;
    
  string results;
  int MoodtoAdd = 0;
  int SumMoodMoe = 0;
  int SumMoodCBG = 0;
  
  for(int i=0; i < NumC; i++)
  {
    results = "";
    results = A[i].getPref();
    
    if(results == "1")
    {
      MoodtoAdd = A[i].getMood();
      SumMoodMoe+= MoodtoAdd;
    }
    else
    {
      MoodtoAdd = A[i].getMood();
      SumMoodCBG+= MoodtoAdd;
    }
  }
  cout << endl;
  
  cout << "Moe made a total of $" << Moe.getCash();
  cout << " and finished with " << SumMoodMoe << " Happiness" << endl;
  
  cout << "Comic Book Guy made a total of $" << CBG.getCash();
  cout << " and finished with " << SumMoodCBG << " Happiness" << endl;
  
  cout << endl;
  if(SumMoodMoe > SumMoodCBG)
    cout << "The winner is Moe" << endl;
  else
    cout << "The winner is Comic Book Guy" << endl;
  return 0;
}
