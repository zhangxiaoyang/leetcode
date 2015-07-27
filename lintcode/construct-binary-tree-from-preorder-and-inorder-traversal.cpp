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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    int findIndex(vector<int> v, int value) {
        for (int i = 0; i < (int)v.size(); i++) {
            if (v[i] == value)
                return i;
        }
        return -1;
    }
    TreeNode *_buildTree(vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd) {
        if (preStart > preEnd)
            return NULL;

        int index = findIndex(inorder, preorder[preStart]);
        TreeNode *root = new TreeNode(preorder[preStart]);
        root->left = _buildTree(preorder, preStart + 1, preStart + index - inStart,
            inorder, inStart, index - 1);
        root->right = _buildTree(preorder, preStart + index - inStart + 1, preEnd,
            inorder, index + 1, inEnd);
        return root;
    }
};
