// Programmer: Peter Banko          date: 11-9-2013
// Class and Section: Cs53 Section B
// purpose: to practice OOP, used in hw10

#include "business.h"
#include "customer.h"
#include <fstream>
#include <iostream>
using namespace std;

business::business(string N,float M)
{
  m_name = N;
  m_cash = M;
  
  m_sizeI = 0;
  m_sizeC = 0;
  
  ifstream fin("BusnItem.txt");
  
  for(int i=0; i < 10; i++)
  {  
    getline(fin,m_Item[i]);
  }
}

void business::print()
{
  cout << "Business Name: " << m_name << endl;
  cout << "Customers: ";
  
  for(int i=0; i < m_sizeC; i++)
  {
    if(m_sizeC - i == 1)
    {
      cout << m_X[i].m_name << endl;
    }
    
    cout << m_X[i].m_name << ", ";
  }
  cout << endl;
  
  cout << "Items Available" << endl;
  cout << "---------------" << endl;
  
  for(int i=0; i < m_sizeI; i++)
  {
    cout << m_Item[i] << endl;
  }
  return;
}

void business::Add(customer x)
{
  m_X[m_sizeC] = x;
  m_sizeC++;
}

