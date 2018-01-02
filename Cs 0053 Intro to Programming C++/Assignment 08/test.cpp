// Programmer: Peter Banko          date: 11-3-2013
// Class and Section: Cs53 Section B
// purpose: to write fables for Moe

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "story.h"
using namespace std;

void Bulk(ifstream&fin, ofstream&fout)
{   
  char next; // character being read in
  char word[15]; // word being built
  char rep1[15]; // word 1 being replaced
  char rep2[15]; // word 2 being replaced
  
  int sizeL1=0; // number of lines in list1.txt
  int sizeL2=0; // number of lines in list2.txt
  char size[500]; // allowance to count lines in list1 and list2
  
  char check1[] = {"the"}; // used for replacing following word
  char check2[] = {"a"}; // used for replacing following word
  
  srand(time(NULL));
  
  int f=0; // used for counting words in files
  
  // Finding the number of lines in list1.txt
  strcpy(size, ""); // clears the array
  ifstream xin("list1.txt");
  while(xin.getline(size, 500, '\n'))
    sizeL1++;
  xin.close();
  
  // Findingt eh number of lines in list2.txt
  strcpy(size, "");
  ifstream yin("list2.txt");
  while(yin.getline(size, 500, '\n'))
    sizeL2++;
  yin.close();
  
  // Finding the number of lines in Moe-rals.txt
  char ral[100];
  int size3=0;
  strcpy(ral, "");
  ifstream min("Moe-rals.txt");
  while(min.getline(ral, 100, '\n'))
    size3++;
  min.close();
  
  // Chose Randome Replacement from list1.txt
  int w1 = rand()%(sizeL1+1);
  
  // Chose Randome Replacement from list2.txt
  int w2 = rand()%(sizeL2+1);
  
  while(fin.get(next))
  {
    if(next == '.')
    {
      rant(fout);
    }
    if(f == 1)
    {
      fout << next;
      replace1(rep1, fin, w1, fout);
     }
    
      if(f == 4)
      {
        fout << next;
        replace2(rep2, fin, w2, fout);
      }
      if(f>4)    
      {
        if(!(strcmp(word, check1)) || !(strcmp(word, check2)))
        {
          fout << next;
          TheA(word, rep1, rep2, fin, w1, w2, sizeL2, fout);
        }
        else
        {
          fout << next;
          rest(word, rep1, rep2, fin, w1, w2, fout);  
        }
      }
      else
      {
        fout << next;
        getwords(word, fin, fout);
      }
      f++;
    }
    ifstream rin("Moe-rals.txt");
    int UsE = rand()%(size3+1);
    for(int i=0; i <= UsE; i++)
    {
      strcpy(ral, "");
      rin.getline(ral, 100);
    }
    fout << endl;
    fout << ral;
    fout << endl; 
    fout << "-------------------------------------------------" << endl;
  return;
}

void getwords(char word[], ifstream&fin, ofstream&fout)
{
  char x[2];
  strcpy(word, "");
  

  while(isalpha(fin.peek()))
  {
    fin.get(x[0]);
    x[1] = '\0';
    strcat(word, x);
  }
  
  fout << word;
  return;
}

void replace1(char rep1[], ifstream&fin, const int w1, ofstream&fout)
{
  char x[2];
  strcpy(rep1, "");
  
  char replace1[20];
  
  while(isalpha(fin.peek()))
  {
    fin.get(x[0]);
    x[1] = '\0';
    strcat(rep1, x);
  }
  
  ifstream lin("list1.txt");
  for(int i=0; i < w1+1; i++)
  {
    strcpy(replace1, "");
    lin.getline(replace1, 20);
  }
  fout << replace1;
  lin.close();
  return;
}

void replace2(char rep2[], ifstream&fin, const int w2, ofstream&fout)
{
  char x[2];
  strcpy(rep2, "");
  
  char replace2[20];
  
  while(isalpha(fin.peek()))
  {
    fin.get(x[0]);
    x[1] = '\0';
    strcat(rep2, x);
  }
  
  ifstream sin("list2.txt");
  for(int i=0; i < w2+1; i++)
  {
    strcpy(replace2, "");
    sin.getline(replace2, 20);
  }
  
  fout << replace2;
  sin.close();
  return;
}

void rest(char word[],char rep1[],char rep2[], ifstream&fin, const int w1, const int w2, ofstream&fout)
{
  char x[2];
  strcpy(word, "");
  
  char replace1[20]; 
  char replace2[20];
  
  while(isalpha(fin.peek()))
  {
    fin.get(x[0]);
    x[1] = '\0';
    strcat(word, x);
  }
   
  ifstream lin("list1.txt");
  for(int i=0; i < w1+1; i++)
  {
    strcpy(replace1, "");
    lin.getline(replace1, 20);
  }
  
  ifstream sin("list2.txt");
  for(int i=0; i < w2+1; i++)
  {
    strcpy(replace2, "");
    sin.getline(replace2, 20);
  }
    
  if(!(strcmp(word, rep1)))    
  {
    strcpy(word, "");
    strcpy(word, replace1);
  }
  
  if(!(strcmp(word, rep2)))
  {
    strcpy(word, "");
    strcpy(word, replace2);
  }
  fout << word;
  sin.close();
  lin.close();
  return;  
}

void TheA(char word[], char rep1[], char rep2[], ifstream&fin, const int w1, const int w2, const int size, ofstream&fout)
{
  char x[2];
  strcpy(word, "");

  char replace1[20];
  char replace2[20];
  char replace3[20];

  while(isalpha(fin.peek()))
  {
    fin.get(x[0]);
    x[1] = '\0';
    strcat(word, x);
  }
  
  ifstream lin("list1.txt");
  ifstream sin("list2.txt");  
  
  for(int i=0; i <= w1+1; i++)
  {
    strcpy(replace1, "");
    lin.getline(replace1, 20);
  }
  
  for(int i=0; i < w2+1; i++)
  {
    strcpy(replace1, "");
    sin.getline(replace2, 20);
  }
  
  sin.close();
  
  ifstream pin("list2.txt");

  int A = rand()%(size+1);
  
  
  for(int i=0; i <= A; i++)  
  {
    strcpy(replace3, "");
    pin.getline(replace3, 20);
  }
  
  if(!(strcmp(word, rep1)))
  {
    strcpy(word, "");
    strcpy(word, replace1);
  }
  else if(!(strcmp(word, rep2)))
  {
    strcpy(word, "");
    strcpy(word, replace2);
  }  
  else
  {
    strcpy(word, "");
    strcpy(word, replace3);
  }
  fout << word;
  lin.close();
  pin.close();
  return;
}

void rant(ofstream&fout)
{
  int size=0;
  char fsize[500];
  strcpy(fsize, "");
  ifstream hin("Moe-rants.txt");
  while(hin.getline(fsize, 500, '\n'))
    size++;
  hin.close();
  
  ifstream bin("Moe-rants.txt");
  int Rant = rand()%(size+1);
  
  int Use = rand()%4+1;
  if(Use == 1)  
  {
    for(int i=0; i < Rant; i++)
    {
      strcpy(fsize, "");
      bin.getline(fsize, 500);
    }
    fout << ". ";
    fout << fsize;
  }
  bin.close();
  return;
}
