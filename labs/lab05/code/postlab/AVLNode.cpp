#include "AVLNode.h"
#include <string>

using namespace std;

AVLNode::AVLNode()
{
    value = "";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode()
{
    delete left;
    delete right;

    // to avoid crash on double deletes
    left = NULL;
    right = NULL;
}

AVLNode& AVLNode::operator=(const AVLNode& other)
{
    if (this != &other)
    {
        this->value = other.value;
        this->left = other.left;
        this->right = other.right;
        this->height = other.height;
    }
    return *this;
}