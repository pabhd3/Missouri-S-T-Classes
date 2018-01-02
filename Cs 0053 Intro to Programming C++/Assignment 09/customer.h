// Programmer: Peter Banko          date: 11-9-2013
// Class amd Section: Cs53 Section B
// purpose: to practice OOP, to be used in hw10

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



class customer
{
  private:
    string m_purch[20]; // describes purchases
    short m_numPurch; // number of purchases
    float m_Mny; // spending money available
    string m_name; // customer's name
  public:
    customer():m_numPurch(0),m_Mny(100),m_name(""){;}; // 1
    customer(string N,float M):m_numPurch(0),m_Mny(M),m_name(N){;}; // 2
    bool purchase(string Item); // 3
    
    string getName(); // 4
    float getMny(); // 5
    void setMny(const float Money); // 6
    
    void print(); // 7
};

// 1. Constructor sets the customer to having no purchases, $100, and no name
// Pre: none
// Post: a custom customer is made
// Notes: I couldn't figure out how to make starting money random

// 2. Constructor sets name and money to user defined
// Pre: name must be string, and money must be above 0
// Post: a custom constructor is made

// 3. I couldn't complete this function, since I couldn't finish the Business Class

// 4. This function return class's name member
// Pre: none
// Post: m_name is returned

// 5. This function return class's money member
// Pre: none
// Post: m_Mny is returned

// 6. This function allows user to set Class's money member
// Pre: Money must be above 0
// Post: m_Mny is set to user defined "Money"

// 7. This funtion prints Class info
// Pre: None
// Post: All the Private Member Variables are outputed

// General Notes: I was not able to get the Business Class to compile.
//                So any functions associated with that class are
//                not included. I was able to have this class compile
//                and run perfectly, except for purchase function.
#endif
