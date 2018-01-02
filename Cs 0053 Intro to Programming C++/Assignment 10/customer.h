// Peter Banko           Cs53
// This is the Customer class used in hw10

#include "product.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

const int MAX_PURCHASES = 10;

const int BUY_GOOD = 15; // customer makes purchase
const int BUY_FAIL = 10; // customer does not make purchase

const int STEAL_GOOD = 25; // thief makes steal
const int V_STEAL_GOOD = 20; // victim gets stolen from
const int STEAL_FAIL = 5; // thief fails the steal

const int TOSS_GOOD = 5; // thrower makes the throw
const int V_TOSS_GOOD = 20; // victim has item thrown at them
const int TOSS_FAIL = 25; // thrower does not make the throw

class customer
{
  private:
    product m_purch[MAX_PURCHASES];
    int m_mood; // customer's happiness
    string m_pref; // customer's inclination
    float m_money;
    int m_bought; // number of items bought
    string m_name;
  public:
    customer():m_purch(),m_mood(rand()%101),m_money((rand()%247)+4),m_bought(0){} // 1
    bool buySomething(const product item); // 2
    void steal(customer&v); // 3
    void toss(customer&v); // 4
    friend ostream&operator<<(ostream&stream,customer&X); // 5
    void setName(const string Name); // 6
    void setPref(const string Pref); // 7
    string getName(); // 8
    string getPref(); // 9
    void Interact(customer&v); // 10
    int getMood(); // 11
};

// 1. This constructor is the default constructor for the class
// Pre: none
// Post: purchases is set to empty, random money is set, random mood is set,
//       and number of purchases is set to zero 

// 2. This function forces the customer into a sale
// Pre: a randomly chosen product is needed
// Post: the customer either buys or doesn't buy the sent product

// 3. This function simulates a customer stealing an item
// Pre: a "victim" needs to be designated
// Post: the calling-object will either steal an item from the victim
//       or not, and adjust their happiness accordingly, and the item
//       transfers from victim to theif, if successful

// 4. This function simulates a customer throwing an item
// Pre: a "victim" needs to be designated
// Post: the calling-object will either throw or not and item from
//       their product list, and adjust happiness accordingly

// 5. This function overloads the extraction operator
// Pre: a designated stream and a desired calling-object
// Post: the customer's name, money, happiness, and bought items are output

// 6. this mutator allows the object's name to be set
// Pre: the desired name
// Post: the object's name is set to the sent string

// 7. this mutator allows the object's preference to be set
// Pre: the desired preference
// Post: the object's name is set to the sent string

// 8. this accessor gets the object's name
// Pre: none
// Post: the object's name is returned

// 9. this accessor gets the object's preference
// Pre: none
// Post: the object's preference is returned

// 10. this function simulates interaction between two customers
// Pre: the victim must be designated
// Post: the interaction between the calling-object and the
//       victim takes place, and their happiness is adjusted

// 11. this accessor gets the onject's mood
// Pre: none
// Post: the object's mood is returned

#endif
