#pragma once
#include <iostream>
#include <string>

using namespace std;

class DoublyLL{
  public:
    struct Node{
      string data;
      Node *next;
      Node *prev;
      Node(string s, Node* p = nullptr, Node *p2 = nullptr){
      data = s;
      next = p;
      prev = p2;
      }
    };
    DoublyLL();
    ~DoublyLL();
    void append(string s);
    void prepend(string s);
    bool remove(string searchKey);
    void print() const;
    void printBackwards() const;
    

  private:
    Node* head;
    Node* tail;
};