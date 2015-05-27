#include <iostream>
#include <stdlib.h>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int length = 0;
        ListNode* node = head;
        while(node) {
            node = node->next;
            length++;
        }
        
        k = k % length;
        if(!length || !k) return head;
        
        ListNode* p = head;
        ListNode* q = head;
        for(int i = 0; i < k; i++) p = p->next;
        while(p->next) {
            p = p->next;
            q = q->next;
        }

        ListNode* newHead = q->next;
        q->next = NULL;
        p->next = head;
        return newHead;
    }
};

int main(int argc, char* argv[]) {
    ListNode nodes[] = {1, 2, 3, 4, 5};
    ListNode* head = &nodes[0];
    for(int i = 0; i < 4; i++) {
        nodes[i].next = &nodes[i+1];
    }

    printList(head);
    printList(Solution().rotateRight(head, 2));
}
