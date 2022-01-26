/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P01
*  Title:            Program 1 - Resizing Stack
*  Course:           3013-Algorithms
*  Semester:         Spring 2022
* 
*  Description:
*        This program resizes an array based stack by growing or shrinking 
*        it depending if the stack is too full or too empty.
*        (Base code credit: @rugbyprof)
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

void openFiles(ifstream& inFile, ofstream& outFile);


/**
* ArrayStack
* 
* Description:
*      Array based stack
* 
* Public Methods:
*      - See class below
* 
* Usage: 
*      - See main program
*      
*/
class ArrayStack {
private:
  int *A;               // pointer to array of int's
  int size;             // current max stack size
  int top;              // top of stack
  int cmdsAmnt = 0;     // Amount of inputs read from a file
  int timesResized = 0; // Amount of times stack was resized
  int maxSize;          // Max size the stack reached
  
  double fullThreshold = .85;
  double emptyThreshold = 0.15;
  double growthAmnt = 2.0;
  double shrinkAmnt = 0.5;

  // top = number of items in the stack + 1
  // size = array size

  // size = 100
  // (top + 1) / size

public:
  /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack() {
    size = 10;
    maxSize = size;
    A = new int[size];
    top = -1;
  }

  /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s) {
    size = s;
    maxSize = size;
    A = new int[s];
    top = -1;
  }

  /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty() {
    return (top < 0);
  }

  /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full() {
    // cout << "\nFull Function Start\n";
    // printf("Top: %i\nSize: %i\nTop/Size: %i", top, size, top/size);
    return (top >= size - 1);
  }

  /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek() {
    if (!Empty()) {
      return A[top];
    }

    return -99; // some sentinel value
                // not a good solution
  }

  /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop() {
    CheckResize();
    if (!Empty()) {
      cmdsAmnt++;
      return A[top--];
    }

    return -99; // some sentinel value
                // not a good solution
  }

  /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print() {
    for (int i = 0; i <= top; i++) {
      cout << A[i] << '\n';
    }
    cout << endl;
  }

  /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  void Push(int x) {
    CheckResize();
    A[++top] = x;
    cmdsAmnt++;
  }

  /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow() {
    int newSize = size * growthAmnt;    // double size of original
    if (newSize > maxSize) {
      maxSize = newSize;
    }

    int *B = new int[newSize]; // allocate new memory

    for (int i = 0; i < size; i++) { // copy values to new array
      B[i] = A[i];
    }

    delete[] A; // delete old array

    size = newSize; // save new size

    A = B; // reset array pointer
  }

  /**
  * Public void: ContainerShrink
  * 
  * Description:
  *      Resizes the container for the stack by halving
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerShrink() {
    int newSize = size * 0.5;    // double size of original

    int *B = new int[newSize]; // allocate new memory

    for (int i = 0; i < top; i++) { // copy values to new array
        B[i] = A[i];
    }

    delete[] A; // delete old array

    size = newSize; // save new size

    A = B; // reset array pointer
  }

  /**
  * Public void: CheckResize
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void CheckResize() {
    double ratio = double(top)/double(size);
    
    if (ratio > fullThreshold) {
      ContainerGrow();
      timesResized++;
    }
    else if (ratio <= emptyThreshold) {
      if (!(size <= 10)) {
        ContainerShrink();
        timesResized++;
      }
    }
  }

  /**
  * Public void: SetFullThreshHold
  * 
  * Description:
  *      Sets the thresh hold for when the stack should grow
  * 
  * Params:
  *      double fth - Thresh hold for when the stack should grow
  * 
  * Returns:
  *      NULL
  */
  void SetFullThreshHold(double fth) {
    fullThreshold = fth;
  }

  /**
  * Public void: SetEmptyThreshHold
  * 
  * Description:
  *      Sets the thresh hold for when the stack should shrink
  * 
  * Params:
  *      double eth - Thresh hold for when the stack should shrink
  * 
  * Returns:
  *      NULL
  */
  void SetEmptyThreshHold(double eth) {
    emptyThreshold = eth;
  }

  /**
  * Public void: SetGrowthAmount
  * 
  * Description:
  *      Sets the amount that the stack should grow when it does
  * 
  * Params:
  *      double gAmnt - Amount the stack should grow by
  * 
  * Returns:
  *      NULL
  */
  void SetGrowthAmount(double gAmnt) {
    growthAmnt = gAmnt;
  }

  /**
  * Public void: SetGrowthAmount
  * 
  * Description:
  *      Sets the amount that the stack should shrink when it does
  * 
  * Params:
  *      double sAmnt - Amount the stack should shrink by
  * 
  * Returns:
  *      NULL
  */
  void SetShrinkAmount(double sAmnt) {
    shrinkAmnt = sAmnt;
  }

  /**
  * Public void: GetResults()
  * 
  * Description:
  *      Outputs the state of the stack when this function is called
  * 
  * Params:
  *      
  * 
  * Returns:
  *      NULL
  */
  void GetResults() {
    cout << "#############################################################\n";
    cout << "\tAssignment 4 - Resizing the Stack\n";
    cout << "\tCMPS 3013\n";
    cout << "\tKolten Pulliam\n\n";

    cout << "\tConfig Params:\n";
    printf("\t\tFull Threshold: %f\n", fullThreshold);
    printf("\t\tEmpty Threshold: %f\n", emptyThreshold);
    printf("\t\tGrowth Ratio: %f\n", growthAmnt);
    printf("\t\tShrink Ratio: %f\n", shrinkAmnt);

    printf("\n\tProcessed %i commands.\n\n", cmdsAmnt);

    printf("\tMax Stack Size: %i\n", maxSize);
    printf("\tEnd Stack Size: %i\n", size);
    printf("\tStack Resized: %i\n", timesResized);
    cout << "#############################################################\n";
  }
};

void CheckBit(ArrayStack &Stack, int x);

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main(int argc, char **argv) {
  ifstream inFile("nums_test.dat");
  ofstream outFile("testOut.txt");
  // openFiles(inFile, outFile);

  ArrayStack stack;

  stack.SetFullThreshHold(stod(argv[1]));
  stack.SetEmptyThreshHold(stod(argv[2]));
  stack.SetGrowthAmount(stod(argv[3]));
  stack.SetShrinkAmount(stod(argv[4]));

  int x;
  while(!inFile.eof()) {
    inFile >> x;
    // Checks if value is even or not
    CheckBit(stack, x);
  }

  stack.GetResults();

  return 0;
}

/**
* @brief Function: openFiles 
* 
* Opens the files we want to use and create.
* 
* @param ifstream& inFile - The input file we are pulling data from.
* @param ofstream& outFile - The output file we are sending data to.
* 
* @return void
*/
void openFiles(ifstream& inFile, ofstream& outFile){
  string inFileName;
  string outFileName;

  // Checks if the input file opened
  cout << "Please give the name of the input file...\n";
  cin >> inFileName;
  inFile.open(inFileName);
  while (!inFile.is_open()){
    cout << "The input file did not open, please try again...\n";
    cin >> inFileName;
  }
  cout << "The input file is now open.\n";

  // Checks if the output file opened
  cout << "Please give the name of the output file...\n";
  cin >> outFileName;
  outFile.open(outFileName);
  while (!outFile.is_open()){
    cout << "The output file did not open, please try again...\n";
    cin >> outFileName;
  }
  cout << "The output file is now open.\n";
}

// Tests whether or not a number is even or odd.
// even = push, odd = pop
void CheckBit(ArrayStack &Stack, int x) {
  if (!(x&1)) {
    Stack.Push(x);
  }else{
    Stack.Pop();
  }
}