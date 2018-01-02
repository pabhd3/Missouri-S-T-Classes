// Programmer: Peter Banko              date: 9/27/2013
// Class and Section: Cs53 Section B
// purpose: to help moe with fractions

#include <iostream>
using namespace std;

// Structures
struct frac 
{
  int m_Num;
  int m_Denom;
};

// Functions

// This function displays a greeting message
// Pre: none
// Post: a message is output
void Greetings();

// This function displays a goodbye message
// Pre: none
// Post: a message is output
void GoodBye();

// This funtion displays the menu containing the available choices
// Pre: none
// Post: a menu is output
void Menu();

// This function obtains and returns a fraction's numerator and denominator
// Pre: both the numerator and denominator cannot be 0
// Post: returns a fraction containing a numerator and denominator
frac get_frac(frac f);

// This function displays a function's numerator and denominator
// Pre: must be a fraction
// Post: returns a fraction's numerator and denominator
frac frac_dis(frac f);

// This function calculates the sum of fraction A and fraction B, and returns
//     the sum as a new fraction
// Pre: must have two fractions
// Post: returns sum of fraction A and fraction B
frac frac_add(frac fA,frac fB);

// This function divides fraction A by fraction B, and returns the result
// Pre: must have two fractions
// Post: returns the result of fraction A divided by fraction B
frac f_divide(frac fA,frac fB);

// This function takes a fraction, and brings it the simpilest form
// Pre: must be a fraction
// Post: returns a fraction's simplified version
frac frac_simp(frac f);

int main()
{
  // Declarations
  frac f1, f2, fSum, f_div;
  int choice;
  const string PROMPT = "Please chose an option listed above:";
  bool quit=false;
  frac fSim1, fSim2;
           
  // Program
  Greetings();
  cout << endl;
  do
  {
    Menu();
    cout << endl;
    cout << PROMPT;
    cin >> choice;
    cout << endl;
    switch(choice)
    {
      case 1:
      {
        cout << "Fraction A" << endl;
        f1= get_frac(f1);
        cout << endl;
        cout << "Fraction A is currently ";
        frac_dis(f1);
        cout << endl;
        cout << endl;
        cout << "Fraction B" << endl;
        f2=get_frac(f2);
        cout << endl;
        cout << "Fraction B is currently ";
        frac_dis(f2);
        cout << endl;
        cout << endl;
        do
        {       
          Menu();
          cout << endl;
          cout << PROMPT;
          cin >> choice;
          cout << endl;
          switch(choice)
          {
            case 1:
            {
              cout << "Fraction A" << endl;
              f1=get_frac(f1);
              cout << endl;
              cout << "Fraction A is currently ";
              frac_dis(f1);
              cout << endl;
              cout << "Fraction B" << endl;
              f2=get_frac(f2);
              cout << endl;
              cout << "Fraction B is currently ";
              frac_dis(f2);
              cout << endl;
              break; 
            }
            case 2:
            {
              frac_dis(f1);
              cout << " + ";
              frac_dis(f2);
              cout << " = ";
              fSum= frac_add(f1,f2);
              frac_dis(fSum);
              cout << endl;
              cout << endl;
              break;
            }
            case 3:
            {
              frac_dis(f1);
              cout << " / ";
              frac_dis(f2);
              cout << " = ";
              f_div= f_divide(f1,f2);
              frac_dis(f_div);
              cout << endl;
              cout << endl;
              break;
            }
            case 4:
            {
              frac_dis(f1);
              cout << " simplifies to ";
              fSim1= frac_simp(f1);
              frac_dis(fSim1);
              cout << endl;
              frac_dis(f2);
              cout << " simplifies to ";
              fSim2= frac_simp(f2);
              frac_dis(fSim2);
              cout << endl;
              cout << endl;
              break;
            }
            case 5:
            {
              quit = true;
              GoodBye();
              break;
            }
            default:
              cout << "ERROR: Invalid Input" << endl;
          }
        }while(!quit);
        break;
      }
      case 2:
      case 3:
      case 4:
        cout << endl;
        cout << "You need to enter fractions before continuing" << endl;
        cout << endl;
        break;
      case 5:
        quit = true;
        GoodBye();
        break;
      default:
        cout << endl;
        cout << "ERROR: Invalid Input" << endl;
        cout << endl;
    }
  }while(!quit);
  return 0;
}

// Function Definitions

void Greetings() // Welcome Message
{
  cout << "Welcome to the wonderful world of fractions" << endl;
  return;
}

void Menu() // Display Menu options
{
  cout << "          Menu" << endl;
  cout << "1. Enter Fractions" << endl;
  cout << "2. Add Fractions" << endl;
  cout << "3. Divide Fractions" << endl;
  cout << "4. Simplify Fractions" << endl;
  cout << "5. Quit" << endl;
  return;
}

frac get_frac(frac f)
{
  cout << "Please enter value of numerator: ";
  cin >> f.m_Num;
  cout << "Please enter value of denominator: ";
  cin >> f.m_Denom;
  return f;
}
 
frac frac_dis(frac f)
{
  cout << "(" << f.m_Num << "/" << f.m_Denom << ")";
  return f;
}

frac frac_add(frac fA,frac fB)
{
  int numX,numY;
  frac fSum;
  fSum.m_Denom= fA.m_Denom * fB.m_Denom;
  numX= fA.m_Num * fB.m_Denom;
  numY= fB.m_Num * fA.m_Denom;
  fSum.m_Num= numX + numY;
  return fSum;
}

frac f_divide(frac fA,frac fB)
{
  frac fdiv;
  fdiv.m_Num = fA.m_Num *  fB.m_Denom;
  fdiv.m_Denom = fB.m_Num * fA.m_Denom;
  return fdiv;
}

frac frac_simp(frac f)
{
  frac fSim;
  if(f.m_Num == f.m_Denom)
    cout << "1" << endl;
  else
  {
    
    for(int i=(f.m_Num<f.m_Denom?f.m_Num:f.m_Denom); i>1; i--)
    {
      if(f.m_Num%i==0 && f.m_Denom%i==0)
      {     
        f.m_Num/= i;
        f.m_Denom/= i;
      }
    }
  }
  fSim.m_Num=f.m_Num;
  fSim.m_Denom=f.m_Denom;
  return fSim;
}

void GoodBye()
{
  cout << "We hope you had a fun time, come back soon" << endl;
  return;
}  
