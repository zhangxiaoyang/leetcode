#include <stdlib.h>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* currentNode, TreeNode* node) {
        if (currentNode == NULL)
            return node;
        if (node == NULL)
            return currentNode;

        if (currentNode->left == NULL && node->val < currentNode->val)
            currentNode->left = node;

        if (currentNode->right == NULL && node->val > currentNode->val)
            currentNode->right = node;

        if (node->val < currentNode->val)
            insertNode(currentNode->left, node);
        else        
            insertNode(currentNode->right, node);
        
        return currentNode;
    }
};
