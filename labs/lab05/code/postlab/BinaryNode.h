#ifndef BINARY_NODE
#define BINARY_NODE

#include <string>

class BinaryNode {
  BinaryNode();
  ~BinaryNode();
  BinaryNode& operator=(const BinaryNode& other);

  std::string value;
  BinaryNode* left;
  BinaryNode* right;

  friend class BinarySearchTree;
};

#endif //BINARY_NODE