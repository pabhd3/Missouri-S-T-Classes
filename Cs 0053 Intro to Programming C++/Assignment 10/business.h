// Peter Banko                    Cs53
// this is the business class for hw10

#ifndef BUSINESS_H
#define BUSINESS_H

#include "customer.h"
using namespace std;

const int MAX_ITEMS = 20;
const int MAX_CUSTOMERS = 20;

class business
{
  private:
    short m_Psize; // number of products available
    short m_Csize; // number of customers in business
    string m_name;
    float m_cash; // in the business' register
    product m_Available[MAX_ITEMS]; // products in the business
    customer m_In[MAX_CUSTOMERS]; // customers in the business
    int m_itemLine;
  public:
    business():m_Psize(0),m_Csize(0),m_cash(0),m_Available(),m_In(){} // 1
    void addCustomer(const customer&c); // 2
    void SellStuff(); // 3
    void Leave(customer x[],int&size); // 4
    void setName(const string Name); // 5
    friend ostream&operator<<(ostream&stream,business&b); // 6
    void setPname(const string name); // 7
    void StringtoFloat(ifstream&fin); // 8
    float getCash(); // 9
    short getCsize(); // 10
    void setItemLine(const int line); // 11
};

// 1. this is the default constructor for the class
// Pre: none
// Post: the number of products is set to 0, number of customers is set to 0,
//       amount of cash is set to 0, number of items available is cleared, and
//       customers in the business is cleared

// 2. this function adds a customer to the customers in the store
// Pre: information on the desired customer to be added
// Post: the desired customer is added to store's customer array

// 3. this function forces the customer into a sale
// Pre: none
// Post: the customers in the business eith buy something, or not

// 4. this function emulates a customer leaving a business
// Pre: an array for customer to move to, and size of said array
// Post: the customer moves from business array to externam array

// 5. the mutator sets the calling-object's name
// Pre: desired name
// Post: calling onject's name is set

// 6. this function overloads the extraction operator
// Pre: stream and object
// Post: business' name nad available products and prices are output

// 7. this mutator sets the callng-object's product name
// Pre: desired name
// Post: the calling object's product name is set

// 8. this function pulls in the price of a product
// Pre: file stream
// Post: the price of the product is set

// 9. this accessor gets cash in business
// Pre: none
// Post: cash in business is returned

// 10. this accessor gets number of customers in business
// Pre: none
// Post: number of customers in business is returned

// 11. this function sets number of lines in item files
// Pre: number of lines in item file
// Post: number of lines in item file is set

#endif
