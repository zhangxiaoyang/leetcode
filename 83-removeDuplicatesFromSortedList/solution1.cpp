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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* next = head->next;

        while(next) {
            if(next->val != prev->val) {
                prev->next = next;
                prev = next;

                next = next->next;
            }
            else {
                ListNode* tmp = next->next;
                //delete next;
                next = tmp;
            }
        }
        prev->next = NULL;
        return head;
    }
};

int main(int argc, char* argv[]) {
    ListNode nodes[] = {1, 1, 3, 3, 5};
    ListNode* head = &nodes[0];
    for(int i = 0; i < 4; i++) {
        nodes[i].next = &nodes[i+1];
    }

    printList(head);
    printList(Solution().deleteDuplicates(head));
}
