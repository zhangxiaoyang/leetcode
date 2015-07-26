#include <iostream>
using namespace std;

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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    return root;
}

int main(int argc, char* argv[]) {
    TreeNode *root = createTree();
    cout<<Solution().maxDepth(root);
}
