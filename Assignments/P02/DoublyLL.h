#pragma once
#include <iostream>
#include <string>
#include <vector>

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
    vector<string> FindRelated(string& word);
    bool isRelated(Node* temp, string& word);
    

  private:
    Node* head;
    Node* tail;
};