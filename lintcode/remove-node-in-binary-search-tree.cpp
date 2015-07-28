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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        TreeNode dummy(INT_MIN);
        dummy.left = root;

        TreeNode* parent = searchNode(&dummy, dummy.left, value);
        if (parent == NULL)
            return dummy.left;

        TreeNode* node = parent->left && parent->left->val == value
            ? parent->left
            : parent->right;
        deleteNode(parent, node);
        return dummy.left;
    }

private:
    TreeNode* searchNode(TreeNode* parent, TreeNode* node, int value) {
        if (node == NULL)
            return NULL;

        if (node->val < value)
            return searchNode(node, node->right, value);
        else if (node->val > value)
            return searchNode(node, node->left, value);
        else
            return parent;
    }

    void deleteNode(TreeNode* parent, TreeNode* node) {
        if (node->left == NULL && node->right == NULL) {
            if (parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else if (node->left == NULL || node->right == NULL) {
            if (parent->left == node)
                parent->left = node->left != NULL
                    ? node->left
                    : node->right;
            else
                parent->right = node->left != NULL
                    ? node->left
                    : node->right;
        }
        else {
            if (parent->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;
            TreeNode* tmp = node->left;
            while (tmp->right != NULL)
                tmp = tmp->right;
            tmp->right = node->right;
        }
        delete node;
    }
};
