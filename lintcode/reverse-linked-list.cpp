#include <iostream>
#include <stack>
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        stack<ListNode*> s;
        ListNode* p = head;

        ListNode dummy(0);
        ListNode* q = &dummy;

        while (p != NULL) {
            s.push(p);
            p = p->next;
        }

        while (!s.empty()) {
            q->next = s.top();
            s.pop();
            q = q->next;
        }
        q->next = NULL;
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
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    int array[] = {1,2,3,4,5,6};
    for (int i = 0; i < (int)(sizeof(array)/sizeof(int)); i++) {
        p->next = new ListNode(array[i]);
        p = p->next;
    }
    printList(head);
    printList(Solution().reverse(head));
}
