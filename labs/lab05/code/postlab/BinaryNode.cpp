#include "BinaryNode.h"
#include <string>

using namespace std;

BinaryNode::BinaryNode()
{
    value = "";
    left = NULL;
    right = NULL;
}

BinaryNode~BinaryNode()
{
    delete left;
    delete right;

    // to avoid crash on double deletes
    left = NULL;
    right = NULL;
}