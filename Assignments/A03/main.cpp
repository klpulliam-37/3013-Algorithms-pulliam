/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            A03
*  Title:            Assingment 3 - Commenting Code
*  Course:           3013 Advanced Structures & Algorithms
*  Semester:         Spring 2022
* 
*  Description:
*        This program creates two linked lists, and adds them together by
*        overloading the addition (+) operator.
* 
*  Usage:
*        N/A
* 
*  Files:            (list of all source files used in this program)
        main.cpp
*****************************************************************************/
#include <iostream>

using namespace std;

int A[100];

/**
 * Node
 * @description: A struct used to contain the data in the linked list.
 * @methods:
 *
 * public:
 *      Node()
 *      Node(int n)
 */
struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * @description: A class used to create a linked list.
 * @methods:
 *
 * public:
 *      List()
 *      void Push(int val)
 *      void Insert(int val)
 *      void PrintTail()
 *      string Print()
 *      int Pop()
 *      List operator+(const List &Rhs)
 *      int operator[](int index)
 *      friend ostream &operator<<(ostream &os, List L)
 */
class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:
    /**
     * @brief Constructor 
     * 
     * Creates a new linked list.
     * 
     * @param N/A
     * 
     * @return N/A
     */
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * @brief Member Function 
     * 
     * Adds a node with an integer value into the linked list.
     * 
     * @param int val - Integer to be added to the list.
     * 
     * @return void
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * @brief Member Function 
     * 
     * Inserts a node into the list at a specific location
     * based on the integer value given.
     * 
     * @param int val - Integer to be added to the list.
     * 
     * @return void
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /**
     * @brief Member Function 
     * 
     * Prints out the ending value of the linked list to the 
     * console.
     * 
     * @param N/A
     * 
     * @return void
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    /**
     * @brief Overloaded Operator 
     * 
     * Allows to lists to be added to each other by creating 
     * an entirely new list which then recieves the values from 
     * each of the old lists by using a pointer to traverse through 
     * each of them.
     * 
     * @param const List&Rhs - The linked list on the right side 
     *                         of the operator.
     * 
     * @return void
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * @brief Overloaded Operator 
     * 
     * Implementation of [] operator. This function returns an
     * int value as if the list were an array.
     * 
     * @param int index - The location of the node within
     *                    the linked list.
     * 
     * @return void
     */
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * @brief Overloaded Operator 
     * 
     * Allows the ostream operator to read a linked list variable
     * and print it out without having to traverse it in main.
     * 
     * @param ostream &os - The ostream object.
     * @param List L - The linked list we want to print out.
     * 
     * @return void
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}