#include <iostream>
#include <stdlib.h>
#include <limits.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode dummy(INT_MAX);
        dummy.next = head;

        ListNode* p = &dummy;
        ListNode* q = p->next;
        ListNode* last = p;

        while(q) {
            if(q->val != p->val) {
                last = p;
                p = p->next; 
                q = q->next;
            }
            else {
                while(q && p->val == q->val) {
                    ListNode* tmp = q;
                    q = q->next;
                    //delete tmp;
                }
                //delete p;
                last->next = q;
                if(q) {
                    p = q;
                    q = q->next;
                }
            }
        }

        return dummy.next;
    }
};

int main(int argc, char* argv[]) {
    ListNode nodes[] = {-3,-1,-1,0,0,0,0,0,2};
    ListNode* head = &nodes[0];
    for(int i = 0; i < sizeof(nodes)/sizeof(ListNode)-1; i++) {
        nodes[i].next = &nodes[i+1];
    }

    printList(head);
    printList(Solution().deleteDuplicates(head));
}
