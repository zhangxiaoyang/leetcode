#include <iostream>

#include <stack>
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }

        stack<ListNode*> s;
        ListNode *right = slow;
        while (right != NULL) {
            s.push(right);
            right = right->next;
        }

        ListNode *left = dummy.next;

        while (left->next != slow) {
            ListNode *tmp = left->next;
            left->next = s.top();
            left->next->next = tmp;
            s.pop();
            left = left->next->next;
        }
        
        while (!s.empty()) {
            left->next = s.top();
            s.pop();
            left = left->next;
        }
        left->next = NULL;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout<<head->val<<' ';
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i = 2; i < 5; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    printList(head);
    Solution().reorderList(head);
    printList(head);
}


