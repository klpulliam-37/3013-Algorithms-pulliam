/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P02
*  Title:            Program 2 - Processing in Linear Time
*  Course:           3013-Algorithms
*  Semester:         Spring 2021
* 
*  Description:
*        This program reads in words from an input file, and creates a 
*        dictionary using a doubly linked list as the back-end data 
*        structure.
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
*       main.cpp
*       DoublyLL.cpp
*       DoublyLL.h
*****************************************************************************/

#include "DoublyLL.h"
#include "timer.hpp"
#include "mygetch.hpp"
#include "termcolor.hpp"
#include <fstream>
#include <vector>

void CreateDict(string fileName, DoublyLL& dict);
vector<string> FindRelated(DoublyLL& dict, string& word);
void PrintWaitMessage();
void RunSearch();

int main() {
  RunSearch();
  return 0;
}

/**
* @brief Function
* 
* Handles the user input in order to run a search on the 
* dictionary.
* 
* @param N/A
* 
* @return void
*/
void RunSearch() {
  string file = "dictionary.txt";
  DoublyLL dict;
  vector<string> related;
  string word;
  char input;

  CreateDict(file, dict);

  while((input = getch()) != 'Z') {
    cout << "\033[2J\033[0;0H"; // Clears the screen
    // Checks if a backspace was pressed
    if ((int)input == 127) {
      // If the word isn't an empty string
      if (word.size() > 0) {
        // Word is equal to itself minus the last character
        word = word.substr(0, word.size() - 1); 
      }
    } else {
        // Make sure a letter was pressed and only letter
        if (!isalpha(input)) {
          cout << "Letters only!" << endl;
          continue;
        }

        // We know its a letter, lets make sure its lowercase.
        // Any letter with ascii value < 97 is capital so we
        // raise it.
        if ((int)input < 97) {
          input += 32;
        }
        word += input; // append char to word
    }

    // Second half of the main functin (searching for related words)

    // Find any words in the list that partially match
    // our substr word
    Timer T;
    T.Start();
    // Finds any related words and stores in a vector
    related = dict.FindRelated(word); 
    T.End();

    // if k is not a space print it
    if ((int)input != 32) {
      cout << "Keypressed: " << termcolor::blue << input << " = " << (int)input << termcolor::reset << endl;
      cout << "Current Substr: " << termcolor::red << word << termcolor::reset << endl;
      cout << '\n';
      cout << T.Seconds() << " seconds to find " 
            << related.size() << " words in the list.\n";
      cout << "Words Found: ";
      cout << termcolor::green;
      // This prints out the first ten matches
      if (word.size() != 0) {
          if(related.size() >= 10){
            for (int i = 0; i < 10; i++) {
              cout << related[i] << " ";
            }
          }else if(related.size() == 0) {
            cout << "no matches for input given...\n";
          }else if(related.size() < 10) {
            for (int i = 0; i < related.size(); i++) {
              cout << related[i] << " ";
            }
          }
          
          cout << endl << endl;
        }else{
          cout << "no matches for input given...\n";
        }
      cout << termcolor::reset << endl
            << endl;
    }
  }
}

/**
* @brief Function
* 
* Creates a dictionary by taking input from a file and
* populating nodes in a linked list with said data.
* 
* @param string fileName - Name of file to open
* @param Doublly& dict - Linked list used as dictionary
* 
* @return void
*/
void CreateDict(string fileName, DoublyLL& dict) {
  ifstream inFile(fileName);
  string word;
  Timer T; // Creates a timer

  T.Start();

  while(!inFile.eof()) {
    inFile >> word;
    dict.append(word);
  }

  T.End();

  cout << T.Seconds() << " seconds to read in the txt file.\n";
  cout << "The input file is ready!\nYou may now start seaching...\n";
}