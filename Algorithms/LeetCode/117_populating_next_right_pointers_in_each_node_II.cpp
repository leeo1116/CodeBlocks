#include "Leetcode.h"


void Solution::Connect(TreeLinkNode *root){
    TreeLinkNode *tmpChild = new TreeLinkNode(0);
    while(root != NULL){
        TreeLinkNode *currentChild = tmpChild;
        while(root != NULL){
            if(root->left != NULL){
                currentChild->next = root->left;
                currentChild = currentChild->next;
            }
            if(root->right != NULL){
                currentChild->next = root->right;
                currentChild = currentChild->next;
            }
            root = root->next;
        }
        root = tmpChild->next;
        tmpChild->next = NULL;
    }
}
