/*
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
#include <stdio.h>
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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int leftCount = maxDepth(root->left);
        int rightCount = maxDepth(root->right);
        
        return (leftCount > rightCount ? leftCount : rightCount) + 1;
    }
};