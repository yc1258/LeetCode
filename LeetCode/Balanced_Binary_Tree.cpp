/*
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (abs(height(root->left) - height(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return (left > right ? left : right) + 1;
    }
};