#include <vector>
#include <algorithm>
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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> result;
        _searchRange(root, k1, k2, result);
        sort(result.begin(), result.end(), less<int>());
        return result;
    }

private:
    void _searchRange(TreeNode *root, int k1, int k2, vector<int> &result) {
        if (root == NULL)
            return;

        if (root->val < k1)
            return _searchRange(root->right, k1, k2, result);
        if (root->val > k2)
            return _searchRange(root->left, k1, k2, result);

        result.push_back(root->val);
        _searchRange(root->left, k1, k2, result);
        _searchRange(root->right, k1, k2, result);
    }
};
