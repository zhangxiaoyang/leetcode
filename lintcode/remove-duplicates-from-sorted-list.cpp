#include <iostream>
using namespace std;

#include <stdlib.h>
#include <limits.h>

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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(INT_MIN);
        dummy.next = head;

        ListNode* p = &dummy;
        while (p != NULL && p->next != NULL) {
            if (p != &dummy && p->val == p->next->val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                continue;
            }
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
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i = 2; i < 60; i++) {
        p->next = new ListNode(i/2);
        p = p->next;
    }

    printList(head);
    Solution().deleteDuplicates(head);
    printList(head);
}
