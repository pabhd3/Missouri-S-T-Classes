// Programmer: Peter Banko          date: 10-15-2013
// Class and Section: Cs53 Section B
// purpose: to make a dart game for Moe

#include "dart.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Function Definition
int get_beer()
{
  int beers;
  cout << "How many beers have you had: ";
  cin >> beers;
  return beers;
}

void display(const int beers)
{
  int score;
  
  score = beers / 2;
  
  cout << "Your score is " << score << endl;
  
  return;
}

void play(float x[], float y[], float score[], const int beers)
{
  float h[SHOTS], v[SHOTS];
  const float PI = 3.14159;
  const int DISTANCE = 13;
  
  for(int i=0; i< SHOTS; i++)
  {
    h[i] = (rand()%(1+(4*beers))-(2*beers)) * (PI/180);
    v[i] = (rand()%(1+(4*beers))-(2*beers)) * (PI/180);
  }  
  
  for(int i=0; i< SHOTS; i++)
  {
    x[i] = DISTANCE * (sin(h[i]) / cos(v[i]));
    y[i] = DISTANCE * (sin(h[i]) / (cos(h[i]) * cos(v[i])));
  }
  
  for(int i=0; i< SHOTS; i++)
  {
    score[i] = sqrt( (x[i]*x[i]) + (y[i]*y[i]) );
  }
  return;
}

void dis(float x[], float y[], float score[], const int beers, string sound[])
{
  float Sum = 0;
  float score_avg; 
    
  for(int i=0; i< SHOTS; i++)
  {
    cout << "x = " << x[i];
    cout << "   ";
    cout << "y = " << y[i];
    cout << "   ";
    cout << "distance = " << score[i];
    cout << "   ";
    Sum+= score[i];
    
    if(score[i] >= 0 && score[i] < 1)
      cout << sound[0] << endl;
      
    else if(score[i] >= 1 && score[i] < 2)
      cout << sound[1] << endl;
      
    else if(score[i] >= 2 && score[i] < 3)
      cout << sound[2] << endl;
      
    else if(score[i] >= 3 && score[i] < 4)
      cout << sound[3] << endl;
      
    else
      cout << sound[4] << endl;  
  }
  score_avg = (Sum / SHOTS ) / beers;
  cout << "Score is " << score_avg << endl;
  
  float handicap[SHOTS];
  
  for(int i=0; i< SHOTS; i++)
    handicap[i] = ((Sum / SHOTS) - score[i])*((Sum/SHOTS)-score[i]);
  
  float handicap_sum = 0;
  
  for(int i=0; i< SHOTS; i++)
    handicap_sum+= handicap[i];  
    
  float handicap_score;
  
  handicap_score = (1.0/SHOTS) * handicap_sum;
    
  cout << "Handicap Score is " << handicap_score << endl;
  return;
}

void dis(float score[], const int beers)
{
  float Sum =0;
  
  for(int i=0; i<10; i++)
  {
    cout << "Distance = " << score[i] << endl;
    Sum+= score[i];
  }
  
  float score_avg = Sum / SHOTS;
  
  cout << "Score is " << score_avg / beers << endl;;
  
  float handicap[SHOTS];
  
  for(int i=0; i<10; i++)
    handicap[i] = (score_avg - score[i]) * (score_avg - score[i]);
  
  float handicap_sum = 0;
  
  for(int i=0; i<10; i++)
    handicap_sum+= handicap[i];
  
  float handicap_score;
  
  handicap_score = (1.0/SHOTS) * handicap_sum;  
  
  cout << "Handicap Score is " << handicap_score << endl; 
  return;
}

void play(float score[])
{
  for(int i=0; i<10; i++)
  {
    score[i] = rand()%56;
    score[i]/= 10;
  }
  return;  
}
