#include "BinaryNode.h"
#include <string>

using namespace std;

BinaryNode::BinaryNode()
{
    value = "";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode()
{
    delete left;
    delete right;

    // to avoid crash on double deletes
    left = NULL;
    right = NULL;
}

BinaryNode& BinaryNode::operator=(const BinaryNode& other)
{
    if (this != &other)
    {
        this->value = other.value;
        this->left = other.left;
        this->right = other.right;
    }
    return *this;
}