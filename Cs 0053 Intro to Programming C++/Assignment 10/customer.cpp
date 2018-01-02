// Peter Banko                 Cs53
// Implimentation file for Customer Class

#include "customer.h"
#include <iostream>
using namespace std;

bool customer::buySomething(const product item)
{
  bool buy=false;
  int choice = rand()%2;
  
  //      check inventory               can afford            want to buy
  if((m_bought < MAX_PURCHASES)&&(m_money > item.m_Pprice)&&(choice == 1))
  {
    m_purch[m_bought] = item; // transfer item
    m_bought++; // number item own increase
    m_money-= item.m_Pprice; // lose the money
    m_mood+= BUY_GOOD; // increase happiness
    cout << m_name << " bought a " << item.m_Pname << " for $" << item.m_Pprice << endl;
    buy=true; // successful sale
  }
  else
    m_mood-= BUY_FAIL; // decrease happiness
  return buy;
}

void customer::steal(customer&v)
{ 
  int itmN = v.m_bought - 1;
  
  if((m_bought < MAX_PURCHASES)&&(v.m_bought > 0))
  {
    cout << m_name << " stole a " << v.m_purch[itmN].m_Pname << " from " << v.m_name << endl; 
    m_purch[m_bought] = v.m_purch[itmN]; // transfer
    m_bought++;
    v.m_bought--;
    m_mood+= STEAL_GOOD;
    v.m_mood-= STEAL_FAIL;
  }
  else
    m_mood-= STEAL_FAIL;
    
  return;
}

void customer::toss(customer&v)
{ 
  int itmN = m_bought - 1;
   
  if(m_bought > 0)
  {
    cout << m_name << " threw a " << m_purch[itmN].m_Pname << " at " << v.m_name << endl;
    m_bought--;
    m_mood+= TOSS_GOOD;
    v.m_mood-= TOSS_FAIL;
  }
  else
    m_mood-= TOSS_FAIL;
    
  return;
}

ostream& operator<<(ostream&stream,customer&x)
{
  stream << x.m_name; // name
  stream << " has $" << x.m_money; // money
  
  if(x.m_bought == 0)
  {
    stream << " and " << x.m_mood << " happiness"; // happiness
  }
  else
  {
    stream << ", " << x.m_mood << " happiness, and ";
    if(x.m_bought == 0)
    {  
      stream << "no products";
    }
    else
    {
      for(int i=0; i < x.m_bought; i++)
        stream << x.m_purch[i].m_Pname << ", ";
    }
  }  
  return stream;
}

void customer::setName(const string Name)
{
  m_name = Name;
  return;
}

void customer::setPref(const string Pref)
{
  m_pref = Pref;
  return;
}
 
string customer::getName()
{
  return m_name;
}

string customer::getPref()
{
  return m_pref;
}

void customer::Interact(customer&v)
{
  if(m_pref == v.m_pref)
    steal(v);
  else
    toss(v);
    
  return;
}

int customer::getMood()
{
  return m_mood;
}
