// Programmer: Peter Banko          date: 11-3-2013
// Class and Section: Cs53 Section B
// purpose: to make Stories for Moe

#ifndef STORY_H
#define STORY_H
#include <iostream>
using namespace std;

// this function rewrites the first sentence of the input file
// Pre: the word count must be less than 5
// Post: the fable is rewritten in the output file
void getwords(char word[], ifstream&fin, ofstream&fout);

// This function "captures" the second word to be changed throughout the fable
// Pre: the word must be the second word of the input file
// Post: the second word of imput file is saved for comparisons
void replace1(char rep1[], ifstream&fin, const int w1, ofstream&fout);

// This function "captures" the fifth word to be changed throughout the fable
// Pre: the word must be the fifth word of the input file
// Post: the fifth word of imput file is saved for comparisons
void replace2(char rep2[], ifstream&fin, const int w2, ofstream&fout);

// This function runs through the input file, and rewrites it in output file
// Pre: the word, comparisons, input stream, and output stream must be valid
// Post: the fable is rewritten in the output file
void rest(char word[], char rep1[], char rep2[], ifstream&fin, const int w1, const int w2, ofstream&fout);

// This function checks the word following "a" or "the" from the input file
// Pre: the word, comparisons, input stream, output stream, need to be sent
// Post: the word following "a" or "the" is changed in the output file
void TheA(char word[], char rep1[], char rep2[], ifstream&fin, const int w1, const int w2,const int size,ofstream&fout);

// This function will randomly insert one of Moe's rants
// Pre: the file destination needs to be specified
// Post: a rant is randomly sent to the output file
void rant(ofstream&fout);

// This function does the reading of the input file
// Pre:  A valid input and output stream must be sent to the function
// Post: the fable is written in the output file
void Bulk(ifstream&fin, ofstream&fout);

#endif
