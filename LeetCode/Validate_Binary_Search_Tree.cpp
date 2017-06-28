/*
 Given a binary tree, determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 Example 1:
 2
 / \
 1   3
 Binary tree [2,1,3], return true.
 Example 2:
 1
 / \
 2   3
 Binary tree [1,2,3], return false.
*/
#include <stdio.h>
/**
 * Definition for a binary tree node.
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL,NULL);
    }
    
    bool isValidBST(TreeNode* root,TreeNode* floor,TreeNode* ceiling) {
        if (root == NULL) {
            return true;
        }
        if ((ceiling && root->val >= ceiling->val) || (floor && root->val <= floor->val)) {
            return false;
        }
        return isValidBST(root->left,floor,root) && isValidBST(root->right,root,ceiling);
    }
};
