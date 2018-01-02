// Programmer: Peter Banko          date: 8/30/13
// File: hw2
// Purpose: To provide a phone number to all of Moe's customers.

#include <iostream>
using namespace std;

int main()
{
  // Declatarions
  float PNGF = 78;            // Value of Phone Number Gender Factor
  int eye_color;              // Wavelength of user's eye color
  float height_m;             // Height of user in meters
  char gender;                // Gender of user
  string name_f;              // User's first name
  string name_l;              // User's Last name
  float phone_abc;            // First three numbers of User's outputed phone number
  int phone_hijk;             // Last four numbers of user's phone number
  int phone_d;                // Digit d of phone number
  int phone_e;                // Digit e of phone number
  int phone_f;                // digit f of phone number
  int phone_def;              // digits def of phone number

  // Greetings
  cout << "Welcome to Moe's Bar. In a moment, we will begin the process of generating your own personal phone number. " << endl;

  // Prompt user for first name
  cout << "Please enter your first name: " << endl;

  cin >> name_f;

  cout << "Please enter your last name: " << endl;

  cin >> name_l;

  // Prompt user for eye color
  cout << "Please enter your eye color (475 for blue, 510 for green, or 590 for orange: " << endl;

  cin >> eye_color;

  // Prompt user for height
  cout << "Please enter your height ( meters ): " << endl;  

  cin >> height_m;

  // Prompt user for gender  
  cout << "Please enter your gender (0 for female, 1 for male): " << endl;

  cin >> gender;

  // Generation area
  phone_abc = eye_color;                           // Calulation of area code of number

  phone_hijk = (eye_color * height_m/1) + ( gender * PNGF ) + (height_m * height_m );   // Calculation of last four numbers of users phone number

  phone_def = eye_color * height_m;                // Calculation for digits def of phone number

  phone_d = (phone_def%1000)/100;                  // Pulling out digit d

  phone_e = (phone_def%100)/10;                    // Pulling out digit e

  phone_f = (phone_def%10)/1;                      // Pulling out digit f
  
  // I know I could have used a static cast to pull out def, but I prefer this way, for now
 
  // Output area
  cout << "Congratulations, we have successfully generated your personal phone number." << endl;
  cout << name_f << " " << name_l << ", your personal phone number is: " << phone_abc << "-" << phone_d << phone_e << phone_f << "-" << phone_hijk << "." << endl;
  cout << "We hope you have a great time at Moe's Bar, " << name_f << ".";
  cout << endl;

  return 0;
}     
