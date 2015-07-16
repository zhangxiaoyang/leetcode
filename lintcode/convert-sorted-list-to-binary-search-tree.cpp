#include <stdlib.h>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    int getListLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            head = head->next;
            length++;
        }
        return length;
    }
    TreeNode* buildTreeFromList(ListNode* &current, int from, int to) {
        if (from > to)
            return NULL;

        int mid = (from + to) / 2;
        TreeNode* left = buildTreeFromList(current, from, mid - 1);
        TreeNode* father = new TreeNode(current->val);
        current = current->next;
        TreeNode* right = buildTreeFromList(current, mid + 1, to);
        father->left = left;
        father->right = right;
        return father;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int lenght = getListLength(head);
        TreeNode* tree = buildTreeFromList(head, 0, lenght - 1);
        return tree;
    }
};
