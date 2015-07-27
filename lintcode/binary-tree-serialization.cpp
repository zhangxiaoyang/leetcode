#include <vector>
#include <string>
using namespace std;

#include <stdio.h>
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string s;
        _serialize(root, s);
        return s;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        vector<string> values = split(data, ' ');
        int index = 0;
        return _deserialize(values, index);
    }

private:
    void _serialize(TreeNode *root, string &s) {
        if (root == NULL) {
            s += "# ";
            return;
        }

        char tmp[255];
        sprintf(tmp, "%d ", root->val);
        s += tmp;

        _serialize(root->left, s);
        _serialize(root->right, s);
    }

    TreeNode *_deserialize(vector<string> &values, int &index) {
        if (index >= (int)values.size() || values[index] == "#")
            return NULL;
            
        TreeNode *root = new TreeNode(atoi(values[index].c_str()));
        index++;
        root->left = _deserialize(values, index);
        index++;
        root->right = _deserialize(values, index);
        return root;
    }

    vector<string> split(string s, char splitter) {
        const char* base = s.c_str();
        const char *p = base;
        const char *q = base;
        vector<string> v;

        while (*p != '\0') {
            if (p == q) {
                while (*q != splitter && *q != '\0')
                    q++;
            }
            v.push_back(s.substr(p - base, q - p));
            q++;
            p = q;
        }
        return v;
    }
};
