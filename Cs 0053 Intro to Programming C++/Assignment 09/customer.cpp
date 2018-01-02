// Programmer: Peter Banko         date: 11-9-2013
// Class and Section: Cs53 Section B
// purpose: to practice OOP, used in hw10

#include "customer.h"
#include <iostream>
#include <cstring>
using namespace std;


void customer::print()
{
  cout << m_name << " has $" << m_Mny << " and purchases ";
  for(int i=0; i < m_numPurch; i++)
  {
    if(m_numPurch - i == 1)
    {
      cout << m_purch[i] << endl;
    }
    cout << m_purch[i] << ", ";
  }
  cout << endl;
  return;
}

bool customer::purchase(string Item)
{
  bool purch=false;
  
  if(m_Mny > 40)
  {
    m_purch[m_numPurch] = "";
    m_purch[m_numPurch] = Item;
    m_numPurch++;
    purch=true;
  }
  return purch;
}

string customer::getName()
{
  return m_name;
}

float customer::getMny()
{
  return m_Mny;
}

void customer::setMny(const float Money)
{
  m_Mny = Money;
  return;
}
