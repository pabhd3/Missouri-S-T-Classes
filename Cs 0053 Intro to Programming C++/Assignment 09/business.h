// Programmer: Peter Banko          date: 11-9-2013
// Class and Section: Cs53 Section B
// purpose: to practice OOP, to be used in hw10

#ifndef BUSINESS_H
#define BUSINESS_H 
#include "customer.h"
using namespace std;

class business
{
  private:
    string m_name;
    
    float m_cash;
       
    short m_sizeI;
    short m_sizeC;
    
    string m_Item[10];
    customer m_X[10];
    
  public:
    business():m_name(""),m_cash(0),m_sizeI(0),m_sizeC(0){}
    business(string N,float M);
    void print();  
    void Add(customer x);
  
#endif
