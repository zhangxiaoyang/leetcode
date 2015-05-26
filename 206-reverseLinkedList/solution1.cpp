#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* node, ListNode** head) {
        if(node->next->next != NULL) {
            reverse(node->next, head)->next = node;
            return node;
        }
        else {
            *head = node->next;
            node->next->next = node;
            return node;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = NULL;
        reverse(head, &newHead)->next = NULL;
        return newHead;
    }
};

int main(int argc, char* argv[]) {
//    Solution().reverseList(head);
}
