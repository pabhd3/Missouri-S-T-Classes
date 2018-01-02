// Peter Banko                 Cs53
// this is the business class for hw10

#include "business.h"
#include <fstream>
#include <cctype>
using namespace std;

void business::addCustomer(const customer&c)
{ 
  m_In[m_Csize] = c; // actual adding of customer
  
  m_Csize++; // increase customer number in business
  return;
}

void business::SellStuff()
{ 
  bool buy_something = false;
  int prdctNum=1;
  for(int i=0; i < m_Csize; i++)
  {
    prdctNum = rand()%m_itemLine; // chose random product to try to sell
    buy_something = m_In[i].buySomething(m_Available[prdctNum]);
    if(buy_something) // If successful Sale
      m_cash+= m_Available[prdctNum].m_Pprice; // store made money
  }
  return;
}

void business::Leave(customer x[],int&size)
{
  int arr; // spot on array 
  
  for(int i=0; i < m_Csize; i++)
  {
    arr = i + size;
    x[arr] = m_In[i]; // moves customer to "street"
  }  
  size = m_Csize;
  m_Csize=0;
  return;
}

void business::setName(const string Name)
{
  m_name = Name;
  return;
}

ostream&operator<<(ostream&stream,business&b)
{
  stream << "Business: ";
  stream << b.m_name << endl; // name
  
  stream << "Items Offered" << endl;
  stream << "--------------------------" << endl;
  
  for(int i=0; i < b.m_itemLine; i++)
  {
    stream << i << "  ";
    stream << "$" << b.m_Available[i].m_Pprice;
    stream << "     ";
    stream << b.m_Available[i].m_Pname << endl;
  }
  return stream;
}

void business::setPname(const string name)
{
  m_Available[m_Psize].m_Pname = name;
  return;
}

void business::StringtoFloat(ifstream&fin)
{
  float price;
  
  price = 0;
   
  fin>>price;
  m_Available[m_Psize].m_Pprice = price;
    
  m_Psize++;
  return;
}

short business::getCsize()
{
  return m_Csize;
}

float business::getCash()
{
  return m_cash;
}

void business::setItemLine(const int line)
{
  m_itemLine = line;
  return;
}
