// Feel free to edit this file and add functions as necessary

#ifndef BST_H
#define BST_H

#include "BinaryNode.h"

using namespace std;

class BinarySearchTree {
 public:
  BinarySearchTree();
  ~BinarySearchTree();

  // insert finds a position for x in the tree and places it there.
  void insert(const string& x);
  // remove finds x's position in the tree and removes it.
  void remove(const string& x);

  // pathTo finds x in the tree and returns a string representing the path it
  // took to get there.
  string pathTo(const string& x) const;
  // find determines whether or not x exists in the tree.
  bool find(const string& x) const;
  // numNodes returns the total number of nodes in the tree.
  int numNodes() const;
  
  void print();

 private:
  // Declare a root node
  BinaryNode* root;

  // prints a subtree
  // call on root for postorder of full tree
  void postorder(BinaryNode* &current, int indent);

  // Any other methods you need...
};


#endif