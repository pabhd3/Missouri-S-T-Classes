// Programmer: Peter Banko          date: 10-15-2013
// Class and Section: Cs53 Section B
// purpose: to make a dart game for Moe

#ifndef DART_H
#define DART_H
#include <iostream>
using namespace std;

// Global Constant for number of shots per round
const int SHOTS =14;

// This function will find out number of beers player has had
// Pre: none
// Post: number of beers had is returned
int get_beer();

// This function displays score of a person who has had less than 3 beers
// Pre: the number of beers needs to be less than 3
// Post: the integer part of beers divided by 2 is returned
void display(const int beers);

// This function displays the Scorecard of a player 
// Pre: the number of beers need to be greater than 2, and less than 17
// Post: the round's X and Y coordinate, Distance, Regular and Handicap 
//       score, along with a "sound" effect are returned
void dis(float x[], float y[], float score[], const int beers, string sound[]);

// This function displays the score of a round of darts
// Pre: the number of beers needs to be greater than 16
// Post: A random set of distances, along with a Regular and Handicap
//       score is output
void dis(float score[], const int beers);

// This function fills the X and Y coordinate, and calculates distances
// Pre: the number of beers needs to be greater than 2, and less than 17
// Post: An array of X-coordinates, Y-coordinates, and Distances is returned
void play(float x[], float y[], float score[],  const int beers);

// This function randomly fills a distance array
// Pre: the number of beers needs to be greater than 16
// Post: a Distance array with randomly filled floats is returned
void play(float score[]);

#endif
