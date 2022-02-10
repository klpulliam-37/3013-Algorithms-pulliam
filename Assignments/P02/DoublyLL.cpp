#include "DoublyLL.h"

/**
* @brief Constructor 
* 
* Creates a new empty Linked List object
* 
* @param N/A
* 
* @return N/A
*/
DoublyLL::DoublyLL(){
  head = nullptr;
  tail = nullptr;
}

/**
* @brief Deconstructor
* 
* Deletes the Linked List object
* 
* @param N/A
* 
* @return N/A
*/
DoublyLL::~DoublyLL(){
  Node* temp = head;
  while(temp != nullptr){
    Node* deleteMe = temp;
    temp = temp->next;
    delete deleteMe;
  }
}

/**
* @brief Method
* 
* Adds a new node to the end of the list
* 
* @param string s - The word being added to the dictionary
* 
* @return void
*/
void DoublyLL::append(string s){
  if(head == nullptr){
    head = new Node(s);
    tail = head;
  }
  else{
    tail->next = new Node(s, nullptr, tail);
    tail = tail->next;
  }
}

/**
* @brief Method
* 
* Adds a new node to the front of the list
* 
* @param string s - The word being added to the dictionary
* 
* @return void
*/
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

/**
* @brief Method
* 
* Removes a node containing the specified string frome
* the list.
* 
* @param string s - The word being removed from the dictionary
* 
* @return bool
*/
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

/**
* @brief Method
* 
* Prints all of the values within every node of the list 
* in alphabetical order
* 
* @param N/A
* 
* @return void
*/
void DoublyLL::print() const{
  Node* traverse = head;
  while(traverse != nullptr){
    std::cout << traverse->data << "\n";
    traverse = traverse->next;
  }
}

/**
* @brief Method
* 
* Prints all of the values within every node of the list 
* in reverse alphabetical order
* 
* @param N/A
* 
* @return void
*/
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

/**
* @brief Method
* 
* Runs through every node to of the list to check wether or 
* not the current search word is related to the string in the node.
* If it is, then it adds it to a vector, otherwise it ignores it.
* 
* @param string& word - Word that is being compared.
* 
* @return vector<string>
*/
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

/**
* @brief Method
* 
* Compares every letter of the current search word with its 
* matching index in the dictionary word.
* 
* @param Node *temp - Node pointer to access node data
* @param string& word - Word that is being compared.
* 
* @return bool
*/
bool DoublyLL::isRelated(Node *temp, string& word) {
  int size = word.size();
  
  // Checks if our substring is bigger than a dictionary word
  if(word.size() <= temp->data.size()) {
    for(int i = 0; i < size; i++){
      if(temp->data[i] != word[i]) {
        return false;
      }
    }
  }else if(word.size() > temp->data.size()) {
    return false;
  }
  return true;
}