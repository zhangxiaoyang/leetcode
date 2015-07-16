#include <iostream>
using namespace std;

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

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        while (fast != NULL) {
            if (slow == fast && slow != &dummy)
                return true;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    ListNode head(0);
    ListNode node1(0);
    ListNode node2(0);
    head.next = &node1;
    node1.next = &node2;
    node2.next = &head;
    cout<<Solution().hasCycle(&head);
}
