#include <iostream>
using namespace std;

#include <stdlib.h>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        while (l1 != NULL) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while (l2 != NULL) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }

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
    ListNode* l1 = new ListNode(1);
    ListNode* p = l1;
    for (int i = 2; i < 6; i++) {
        p->next = new ListNode(i*2);
        p = p->next;
    }
    printList(l1);

    ListNode* l2 = new ListNode(1);
    p = l2;
    for (int i = 2; i < 6; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    printList(l2);

    printList(Solution().mergeTwoLists(l1, l2));
}
