#ifndef TREENODE_H
#define TREENODE_H


#include<iostream>
#include<stddef.h>


using namespace std;


class TreeNode
{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x);
        virtual ~TreeNode();

        void PrintVal();
    protected:
    private:
};

#endif // TREENODE_H
