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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessList = NULL;
        ListNode* greaterList = NULL;

        ListNode* node = head;
        ListNode* lessNode = NULL;
        ListNode* greaterNode = NULL;
        while(node) {
            if(node->val < x) {
                if(!lessList) {
                    lessList = new ListNode(node->val);
                    lessNode = lessList;
                }
                else {
                    lessNode->next = new ListNode(node->val);
                    lessNode = lessNode->next;
                }
            }
            else {
                if(!greaterList) {
                    greaterList = new ListNode(node->val);
                    greaterNode = greaterList;
                }
                else {
                    greaterNode->next = new ListNode(node->val);
                    greaterNode = greaterNode->next;
                }
            }
            node = node->next;
        }

        if(lessNode) {
            lessNode->next = greaterList;
            return lessList;
        }
        return greaterList;
    }
};

int main(int argc, char* argv[]) {
    ListNode node[] = {1, 4, 3, 2, 5, 2};
    ListNode* head = &node[0];
    for(int i = 0; i < 5; i++) {
        node[i].next = &node[i+1];
    }

    printList(head);
    printList(Solution().partition(head, 3));
}
