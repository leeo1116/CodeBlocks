#include "TreeNode.h"


TreeNode::TreeNode(int x): val(x), left(NULL), right(NULL)
{
    //ctor
}


TreeNode::~TreeNode()
{
    //dtor
}


void TreeNode::PrintVal()
{
    cout << val << endl;
}
