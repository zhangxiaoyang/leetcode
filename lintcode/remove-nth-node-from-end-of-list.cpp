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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n < 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *p = &dummy;
        ListNode *q = &dummy;

        for (int i = 0; i < n + 1; i++) {
            if (q == NULL)
                return dummy.next;
            q = q->next;
        }
        while (q != NULL) {
            p = p->next;
            q = q->next;
        }

        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
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
    for (int i = 2; i < 6; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    p = NULL;

    int n = 2;

    printList(head);
    Solution().removeNthFromEnd(head, n);
    printList(head);
}
