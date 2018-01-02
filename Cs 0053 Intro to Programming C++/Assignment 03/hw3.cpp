// Programmer: Peter Banko                     date: 9/6/13
// Class: Cs 53 Section B
// Description: this program will be a sort of filter to the possible patrons of Moe's Bar


#include <iostream>
using namespace std; 

int main ()
{
  // Declarations
  string name;    // Used for entering name and drink type
  char patron, teetotaler, soda, drink;    // Used for answering a yes/no question
  float age, money, drink_beer, drink_liquor;
  int liquor_max, beer_max;   // Liquor or beer that can be bought with input money
  const float MIN_AGE = 21;     // Minumum age to enter bar
  const float MAX_AGE = 100;    // Maximum age to enter bar
  const float PRICE_BEER = 2.00;     // Price of beer
  const float PRICE_LIQUOR = 4.25;   // Price of Liquor
  bool patron_x = false;     // Used when no more patrons are present
  const string Welcome = "Welcome to Moe's Bar, whats your name?";
  const string More = "Anyone else there? (y/n)";
  const string Remove = "Get out of Here!";
  const string Money = "Come back when you want to spend all your money!";  
  const string Enter = "Come on in, grab a seat at the bar.";
  
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
    
  // Interview
  cout << Welcome << endl;
  do
  {
    cin >> name;
    if (name == "Barney")
    {
      cout << "C'mon in Barney, anyone else there? (y/n)" << endl;
      cin >> patron;
      if (patron == 'y')
        cout << Welcome << endl;
      else
        patron_x = true;  
    } 
    else if(patron_x == false)
    {  
      cout << "Alright " << name << ", are you a teetotaler? (y/n)" << endl; 
      cin >> teetotaler;
      if (teetotaler == 'y')
      {
        cout << Remove << endl;
        cout << More << endl;
        cin >> patron;
        if (patron == 'y')
          cout << Welcome << endl;
        else
          patron_x = true;
      }
      else
      {
        cout << "Alright " << name << ", how old are you?" << endl;
        cin >> age;
        if (age >= MIN_AGE && age < MAX_AGE)
        {             
          cout << "Were you planning on drinking soda tonight?(y/n) " << endl;
          cin >> soda;
          if (soda == 'y')
          {
            cout << "We don't soyrv you sissies in dis place!" << endl;
            cout << More << endl;
            cin >> patron;
            if (patron == 'y')
              cout << Welcome << endl;
            else
            patron_x = true;
          }
          else
          {
            cout << "Alright " << name << " how much money did you bring tonight?" << endl;
            cin >> money;
            if (money < PRICE_BEER)
            {
              cout << "Get outta here ya bum!" << endl;
              cout << More << endl;
              cin >> patron;
              if (patron == 'y')
                cout << Welcome << endl;
              else
                patron_x = true;
            }
            else
            { 
              cout << "Do you want beer or liquor? (b/l)" << endl;
              cin >> drink;                  
              if (drink == 'b')
              {  
                cout << "How many beers are you going to buy?" << endl;  
                cin >> drink_beer;
                           
                beer_max = money / PRICE_BEER;
                             
                if (drink_beer != beer_max)
                {
                  cout << Money << endl;
                  cout << More << endl;
                  cin >> patron;
                  if (patron == 'y')
                    cout << Welcome << endl;
                  else
                    patron_x = true;
                }
                else
                {
                  cout << Enter << endl;
                  cout << More << endl;
                  cin >> patron;
                  if (patron == 'y')
                    cout << Welcome << endl;
                  else
                    patron_x = true;
                }      
              }
              else
              {
                cout << "How many liquor are you going to buy?" << endl;
                cin >> drink_liquor;
                             
                liquor_max = money / PRICE_LIQUOR;
                          
                if (drink_liquor != liquor_max)
                {
                  cout << Money << endl;
                  cout << More << endl;
                  cin >> patron;
                  if (patron == 'y')
                    cout << Welcome << endl;
                  else
                    patron_x = true;
                }
                else
                {  
                  cout << Enter << endl;
                  cout << More << endl;
                  cin >> patron;
                  if (patron == 'y')
                    cout << Welcome << endl;
                  else
                    patron_x = true;
                }
              }          
            }  
          }  
        }
        else
        {
          cout << Remove << endl;
          cout << More << endl;
          cin >> patron;
          if (patron == 'y')
            cout << Welcome << endl;
          else
            patron_x = true;
        }                                                         
      }
    }     
    else
    {
      cout << Remove << endl;
      cout << More << endl;
      cin >> patron;
      if (patron == 'y')
        cout << Welcome << endl;
      else
        patron_x = true;               
    }         
  } while (patron == 'y' && patron_x == false);         
  return 0;
}
