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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isValidBST(TreeNode *root, long min, long max) {
        if (root == NULL)
            return true;
            
        if (min < root->val && root->val < max)
            return _isValidBST(root->left, min, root->val)
                && _isValidBST(root->right, root->val, max);
        return false;
    }
};
