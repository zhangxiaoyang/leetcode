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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    int listLen(ListNode* head) {
        ListNode* p = head;
        int count = 0;
        while (p != NULL) {
            p = p->next;
            count++;
        }
        return count;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k <= 0)
            return head;
        k %= listLen(head);

        ListNode dummy(0);
        dummy.next = head;

        ListNode* p = &dummy;
        ListNode* q = &dummy;

        for (int i = 0; i < k + 1; i++) {
            if (q == NULL)
                return head;
            q = q->next;
        }
        while (q != NULL) {
            p = p->next;
            q = q->next;
        }

        ListNode* newHead = p->next;
        q = newHead;
        p->next = NULL;
        while (q->next != NULL)
            q = q->next;
        q->next = head;
        return newHead;
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
    int array[] = {2,3,4,5};
    for (int i = 0; i < (int)(sizeof(array)/sizeof(int)); i++) {
        p->next = new ListNode(array[i]);
        p = p->next;
    }
    printList(head);
    int k = 2;
    printList(Solution().rotateRight(head, k));
}
