#ifndef AVL_NODE
#define AVL_NODE

#include <string>

class AVLNode {
  AVLNode();
  ~AVLNode();
  AVLNode& operator=(const AVLNode& other);

  std::string value;
  AVLNode* left;
  AVLNode* right;
  int height;

  friend class AVLTree;
};

#endif //AVL_NODE