#include "Leetcode.h"


void Solution::RecoverTree(TreeNode *root){
    InorderTraversal(root);
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}


void Solution::InorderTraversal(TreeNode *root){
    if(root == NULL)
        return;
    InorderTraversal(root->left);
    if(first == NULL && prev->val >= root->val)
        first = prev;
    if(first != NULL && prev->val >= root->val)
        second = root;
    prev = root;
    InorderTraversal(root->right);
}
