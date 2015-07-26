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
    void _preorderTraversal(TreeNode *currentNode, vector<int> &v) {
        if (currentNode == NULL)
            return;
            
        v.push_back(currentNode->val);
        _preorderTraversal(currentNode->left, v);
        _preorderTraversal(currentNode->right, v);
    }
    
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        _preorderTraversal(root, v);
        return v;
    }
};
