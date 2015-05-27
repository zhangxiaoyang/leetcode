#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void printList(ListNode* node) {
    while(node) {
        cout<<node->val<<'\t';
        node = node->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev;
        ListNode* node = &dummy;
        ListNode* first;
        for(int i = 0; i < m-1; i++) {
            node = node->next;
        }
        prev = node;
        node = node->next;
        first = node;

        ListNode* last = first->next;
        for(int i = 0; i < n-m; i++) {
            ListNode* tmp = node;
            node = last;
            last = last->next;
            node->next = tmp;
        }

        prev->next = node;
        first->next = last;
        return dummy.next;
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(9);
    head->next->next->next = NULL;

    printList(head);
    printList(Solution().reverseBetween(head, 2, 2));
}
