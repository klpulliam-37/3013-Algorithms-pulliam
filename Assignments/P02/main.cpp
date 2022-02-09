// File Path of main
// C:\repos\3013-Algorithms-pulliam\Assignments\P02

#include "DoublyLL.h"
#include "timer.hpp"
// #include "mygetch.hpp"
// #include "termcolor.hpp"
#include <fstream>
#include <vector>
#include <conio.h>

void CreateDict(string fileName, DoublyLL& dict);
vector<string> FindRelated(DoublyLL& dict, string& word);

int main() {
    system("CLS");
    string file = "words_test.txt";
    DoublyLL dict;
    vector<string> related;
    string word = "bel";
    char input;

    // cin >> file;

    CreateDict(file, dict);

    Timer T;
    T.Start();
    related = dict.FindRelated(word);
    T.End();

    // This prints out all found matches
    for (int i = 0; i < related.size(); i++) {
        cout << related[i] << " ";
    }

    // while((input = getch()) != 'Z') {
    //     if ((int)input == 127) {
    //         if (word.size() > 0) {
    //             word = word.substr(0, word.size() - 1);
    //         }
    //     } else {
    //         // Make sure a letter was pressed and only letter
    //         if (!isalpha(input)) {
    //             cout << "Letters only!" << endl;
    //             continue;
    //         }

    //         // We know its a letter, lets make sure its lowercase.
    //         // Any letter with ascii value < 97 is capital so we
    //         // lower it.
    //         if ((int)input < 97) {
    //             input += 32;
    //         }
    //         word += input; // append char to word
    //     }

    //     cout << input;

        // Second half of the main functin (searching for related words)

        // Find any words in the list that partially match
        // our substr word
        // related = dict.FindRelated(word);
        // // This prints out all found matches
        // for (int i = 0; i < related.size(); i++) {
        //     cout << related[i] << " ";
        // }

        // if ((int)input != 32) { // if k is not a space print it
        //     cout << "Keypressed: " << termcolor::blue << input << " = " << (int)input << termcolor::reset << endl;
        //     cout << "Current Substr: " << termcolor::red << word << termcolor::reset << endl;
        //     cout << "Words Found: ";
        //     cout << termcolor::green;
        //     // This prints out all found matches
        //     for (int i = 0; i < related.size(); i++) {
        //         cout << related[i] << " ";
        //     }
        //     cout << termcolor::reset << endl
        //          << endl;
        // }
    // }

    // dict.print();
    system("pause");
    system("CLS");

    return 0;
}

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
}

// Finished Finding the related words that match the input/word
