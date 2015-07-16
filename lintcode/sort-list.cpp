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

void printList(ListNode* head) {
    while (head != NULL) {
        cout<<head->val<<' ';
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *getMidOfList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode dummy(0);
        ListNode *iter = &dummy;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                iter->next = p;
                p = p->next;
            }
            else {
                iter->next = q;
                q = q->next;
            }
            iter = iter->next;
        }
        if (p != NULL)
            iter->next = p;
        else
            iter->next = q;
        return dummy.next;
    }
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *mid = getMidOfList(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        return mergeList(sortList(left), sortList(right));
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    head->next = node1;
    node1->next = node2;
    node2->next = NULL;

    printList(head);
    printList(Solution().sortList(head));
}
