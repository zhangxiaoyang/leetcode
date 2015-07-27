#include <queue>
#include <vector>
using namespace std;

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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = (int)q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *currentNode = q.front();
                level.push_back(currentNode->val);
                q.pop();
                if (currentNode->left != NULL)
                    q.push(currentNode->left);
                if (currentNode->right != NULL)
                    q.push(currentNode->right);
            }

            result.push_back(level);
        }

        return result;
    }
};
