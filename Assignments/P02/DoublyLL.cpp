#include "DoublyLL.h"

DoublyLL::DoublyLL(){
  head = nullptr;
  tail = nullptr;
}

DoublyLL::~DoublyLL(){
  Node* temp = head;
  while(temp != nullptr){
    Node* deleteMe = temp;
    temp = temp->next;
    delete deleteMe;
  }
}

void DoublyLL::append(string s){
  if(head == nullptr){
    head = new Node(s);
    tail = head;
  }
  else{
    Node* traverse = head;
    while(traverse->next != nullptr){
      traverse = traverse->next;
    }
    traverse->next = new Node(s, nullptr, traverse);
  }
}

void DoublyLL::prepend(string s){
  if(head == nullptr){
    head = new Node(s, head);
    tail = head;
  }
  else{
    Node *temPtr = new Node(s, head);
    head->prev = temPtr;
    head = temPtr;
  }
}

bool DoublyLL::remove(string searchKey){
  Node *temPtr;
  if(!head){
    std::cout << "The list is empty...\n";
    return true;
  }
  else if(head->data == searchKey){
    temPtr = head;
    head = head->next;
    delete temPtr;
    return true;
  }
  else{
    temPtr = head;
    while(temPtr != nullptr && temPtr->data != searchKey){
      temPtr = temPtr->next;
    }
    if (temPtr){
      temPtr->prev->next = temPtr->next;
      temPtr->next->prev = temPtr->prev;
      delete temPtr;
      return true;
    }
  }
  return false;
}

void DoublyLL::print() const{
  Node* traverse = head;
  while(traverse != nullptr){
    std::cout << traverse->data << "\n";
    traverse = traverse->next;
  }
}

void DoublyLL::printBackwards() const{
  Node* traverse = head;
  while(traverse->next != nullptr){
    traverse = traverse->next;
  }
  while(traverse != nullptr){
    std::cout << traverse->data << "\n";
    traverse = traverse->prev;
  }
}

vector<string> DoublyLL::FindRelated(string& word) {
  vector<string> related;
  Node *temp = head;
    
  while(temp) {
    if(isRelated(temp, word)) {
      related.push_back(temp->data);
    }
    temp = temp->next;
  }

  return related;
}

bool DoublyLL::isRelated(Node *temp, string& word) {
  int size = word.size();
  for(int i = 0; i < size; i++){
    if(temp->data[i] != word[i]) {
      return false;
    }
  }
  return true;
}