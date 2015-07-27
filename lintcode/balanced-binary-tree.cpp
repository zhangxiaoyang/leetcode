#include <stdlib.h>

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return maxDiffDepthOfTree(root) != -1;
    }

private:
    int maxDiffDepthOfTree(TreeNode *root) {
        if (root == NULL)
            return 0;
            
        int left = maxDiffDepthOfTree(root->left);
        int right = maxDiffDepthOfTree(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
