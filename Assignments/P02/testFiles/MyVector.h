#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <array>
using namespace std;

// Node used for the linked list
template <typename T>
struct node{
  T data;
  node *next;
  node *prev;
  node(int x, node* n = nullptr, node *p = nullptr){
    data = x;
    next = n;
    prev = p;
  }
};

/**
 * Class Name
 * 
 * Description:
 *      This class creates a doubly linked list 
 *      which is used to store integers.
 *      It can find given values within it, 
 *      copy values from another linked list, 
 *      and even properly sort the value you would 
 *      like to place into the list.
 * 
 * Public Methods:
 *                          MyVector()
 *                          MyVector(int A[], int size)
 *                          MyVector(string fileName)
 *                          MyVector(MyVector &L1)
 *      void                pushFront(int x)
 *      void                pushRear(int x)
 *      void                pushAt(int x, int point)
 *      void                inOrderPush(int x)
 *      int                 popFront()
 *      int                 popRear()
 *      int                 popAt(int x, int loc)
 *      int                 find(int x)
 *      void                print(ostream& outFile)
 *      void                backwardsPrint(ostream& outFile)
 *      T                   &operator[](int loc)
 *      friend ostream      &operator<<(ostream& cout, const MyVector& V)
 *      friend ofstream     &operator<<(ofstream& cout, const MyVector& V)
 *      MyVector            &operator=(const MyVector &V)
 *      MyVector            operator+(MyVector& other)
 *      MyVector            operator-(MyVector& other)
 *      MyVector            operator/(MyVector& other)
 *      MyVector            operator*(MyVector& other)
 *      bool                operator==(const MyVector& other)
 * 
 * Private Methods:
 *      N/A
 * 
 * Usage: 
 *      
 */
template <typename T>
class MyVector{
  private:
    node<T>* head;
    node<T>* tail;
    // Used to traverse list and locate specific points
    int counter = 0; 
    // Used to get the size of the list for overloaded operators
    int listSize = 0; 
  public:
    MyVector();
    MyVector(int A[], int size);
    MyVector(string fileName);
    MyVector(MyVector &L1);
    void pushFront(int x);
    void pushRear(int x);
    void pushAt(int x, int point);
    void inOrderPush(int x);
    int popFront();
    int popRear();
    int popAt(int x, int loc);
    int find(int x);
    void print(ostream& outFile);
    void backwardsPrint(ostream& outFile);
    T &operator[](int loc);
    friend ostream &operator<<(ostream& cout, const MyVector& V);
    friend ofstream &operator<<(ofstream& cout, const MyVector& V);
    MyVector &operator=(const MyVector &V);
    MyVector operator+(MyVector& other);
    MyVector operator-(MyVector& other);
    MyVector operator/(MyVector& other);
    MyVector operator*(MyVector& other);
    bool operator==(const MyVector& other);
    

  private:
    Node* head;
    Node* tail;
};