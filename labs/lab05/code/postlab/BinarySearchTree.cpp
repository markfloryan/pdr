// Feel free to edit this file and add functions as necessary
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <iomanip> //for setw in postorder

using namespace std;

BinarySearchTree::BinarySearchTree() {}
BinarySearchTree::~BinarySearchTree() {}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {}
// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const { return ""; }
// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const { return false; }
// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const { return -1; }

void BinarySearchTree::print()
{
    postorder(root, 0);
}

// prints a subtree
// call on root for postorder of full tree
void BinarySearchTree::postorder(BinaryNode* &current, int indent)
{
    if(current != NULL) {
        if(current->left) postorder(current->left, indent+4);
        if(current->right) postorder(current->right, indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << current->value << std::endl;
    }
}