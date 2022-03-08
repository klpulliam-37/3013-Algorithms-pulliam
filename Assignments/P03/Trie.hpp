#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int C_SIZE = 26;

struct Node {
  bool isWord;
  Node* children[C_SIZE];

  Node() {
    isWord = false;
    for (int i = 0; i < C_SIZE; i++) {
      children[i] = nullptr;
    }
  }
};

/**
 * Class Name: Trie
 * 
 * Description:
 *      This class creates a trie tree that stores
 *      a list of words in it like a dictionary.
 * 
 * Public Methods:
 *                          Trie()
 *      void                insert(string word)
 *      bool                search(string key)
 *      vector<string>      findRelated(string input)
 *      void                searchAll(Node* curr, string word)
 *      vector<string>      FindRelated(string& word)
 * 
 * Private Methods:
 *      N/A
 * 
 * Usage: 
 *      
 */
class Trie {
  private:
    Node* root;
    vector<string> related;

  public:
    /**
    * @brief Constructor 
    * 
    * Creates a new empty Trie Tree object
    * 
    * @param N/A
    * 
    * @return N/A
    */
    Trie() {
      root = new Node();
    }

    /**
    * @brief Method
    * 
    * Adds a new node for every character in the word to the tree
    * 
    * @param string word - The word being added to the dictionary
    * 
    * @return void
    */
    void insert(string word) {
      Node* curr = root;

      // Checks if the current nodes 
      // children mathces words first character
      for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!curr->children[index]) {
            curr->children[index] = new Node();
          }
          curr = curr->children[index];
      }
 
      // mark last node leaf
      curr->isWord = true;
    }

    /**
    * @brief Method
    * 
    * Searches for a singular word in the tree
    * 
    * @param string key - The word we are searching for
    * 
    * @return bool
    */
    bool search(string key)
    {
      Node* curr = root;
   
      for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!curr->children[index])
          return false;
 
        curr = curr->children[index];
      }
    
      return (curr->isWord);
    }

    /**
    * @brief Method
    * 
    * Traverses through the tree based on our current input
    * 
    * @param string input - The current word typed by user
    * 
    * @return vector<string>
    */
    vector<string> findRelated(string input) {
      string word;
      int index;
      Node* curr = root;

      related.clear();

      for (int i = 0; i < input.length(); i++) {
        index = input[i] - 'a';

        // Checks if the input is bigger than 
        // the current tree length
        if (curr->children[index]) {
          curr = curr->children[index];
        }else{
          return related;
        }
        
      }

      searchAll(curr, input);

      return related;
    }

    /**
    * @brief Method
    * 
    * Traverses every single child underneath a node if there
    * is one
    * 
    * @param Node* curr - The current node to be used in the function call
    * @param string word - The state of the word based on the current node
    * 
    * @return void
    */
    void searchAll(Node* curr, string word) {
      
      if (curr->isWord) {
        related.push_back(word);
      }
      
      for (int i = 0; i < C_SIZE; i++) {
        if (curr->children[i]) {
          searchAll(curr->children[i], word + char(i + 'a'));
        }
      }
    }
};