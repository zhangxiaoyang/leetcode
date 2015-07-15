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
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode left(0);
        ListNode right(0);

        ListNode* iter = head;
        ListNode* p = &left;
        ListNode* q = &right;

        while (iter != NULL) {
            if (iter->val < x) {
                p->next = iter;
                p = p->next;
            }
            else {
                q->next = iter;
                q = q->next;
            }
            iter = iter->next;
        }
        p->next = NULL;
        q->next = NULL;
        if (q != &right)
            p->next = right.next;

        return left.next;
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
    int array[] = {1,4,3,2,5,2};
    for (int i = 0; i < (int)(sizeof(array)/sizeof(int)); i++) {
        p->next = new ListNode(array[i]);
        p = p->next;
    }
    printList(head);
    int x = 3;
    printList(Solution().partition(head, x));
}
