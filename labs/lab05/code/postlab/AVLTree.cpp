// Feel free to edit this file and add functions as necessary
#include "AVLTree.h"
#include "AVLNode.h"
#include <string>
#include <iostream>
#include <iomanip> //for setw in postorder

using namespace std;

// Implement at least the remaining unimplemented methods in AVLTree.h (see below method skeletons)
AVLTree::AVLTree() { }

AVLTree::~AVLTree() { }

void AVLTree::insert(const string& x) { }
string AVLTree::pathTo(const string& x) const { return ""; }
bool AVLTree::find(const string& x) const { return false; }
int AVLTree::numNodes() const { return -1; }
// balance should balance only the single node it is given
void AVLTree::balance(AVLNode*& n) { }
AVLNode* AVLTree::rotateLeft(AVLNode*& n) { return NULL; }
AVLNode* AVLTree::rotateRight(AVLNode*& n) { return NULL; }

/** The following are implemented for you: remove, max, min, and height;
remove finds x's position in the tree and removes it, rebalancing as necessary. **/
void AVLTree::remove(const string& x) { remove(root, x); }

/** private helper for remove to allow recursion over different nodes; 
returns an AVLNode* that is assigned to the original node. **/
bool AVLTree::remove(AVLNode*& current, const string& x) {
  bool returnVal = false;
  // base-case for x not present in tree
  if (current == NULL) 
  {
    returnVal = false;
  }
  // recursively approach base case to left
  else if (x < current->value)
  {
    returnVal = remove(current->left, x);
  }
  // recursively approach base case to right
  else if (x > current->value)
  {
    returnVal = remove(current->right, x);
  }
  // base-case for x present in tree
  else
  {
    // no children
    if(current->left == NULL && current->right == NULL)
    {
      delete current;
      current = NULL;
      returnVal = (current == NULL); // should be true
    }
    // two children
    else if (current-> left != NULL && current->right != NULL)
    {
      AVLNode *rLMost = current->right;
      // find leftmost node in right subtree iteratively
      // this value is the lowest of the values higher than our current value
      // i.e. the middle-most value of this (sub)tree
      while(rLMost->left != NULL)
      {
        rLMost = rLMost->left;
      }
      // replace current with rLMost (value only)
      current->value = rLMost->value;
      // this should immediately reach either base-case present
      // with (above) no children or (below) one child, the right
      // just log more recurse; runtime preserved. 
      returnVal = remove(current->right, rLMost->value);
    }
    // one child
    else
    {
      // if right is not null, then child is right; otherwise child is left
      AVLNode* child = (current->right != NULL) ? current->right : current->left;
      // replace current with child but keep height
      int heightTemp = current->height;
      current = child;
      current->height = heightTemp;
      delete child;
      child = NULL;
      returnVal = (child == NULL); //should be true
    }
  }
  balance(current);
  return returnVal;
  // recall that if this returns true, balance(root) will be called, fixing any inbalance
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

/** height returns the value of the height field in a node. 
If the node is null, it returns 0. **/
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}

void AVLTree::print()
{
  postorder(root, 0);
}

void AVLTree::postorder(AVLNode*& current, int indent)
{
    if(current != NULL) {
        if(current->left != NULL) postorder(current->left, indent+4);
        if(current->right != NULL) postorder(current->right, indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << current->value << std::endl;
    }
}

// non-member(s)
// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}