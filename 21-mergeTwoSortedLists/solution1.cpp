#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    ListNode* p = head;
    while(p) {
        cout<<p->val<<'\t';
        p = p->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* mergedList = NULL;

        if(!l2)
            return l1;
        if(!l1)
            return l2;

        while(p1 && p2) {
            if(p1->val <= p2->val) {
                if(!mergedList)
                    mergedList = p1;

                while(p1->next && p1->next->val <= p2->val) {
                    p1 = p1->next;
                }
                
                ListNode* tmp = p1->next;
                p1->next = p2;
                p1 = tmp;
            }
            else {
                if(!mergedList)
                    mergedList = p2;

                while(p2->next && p2->next->val <= p1->val) {
                    p2 = p2->next;
                }
                
                ListNode* tmp = p2->next;
                p2->next = p1;
                p2 = tmp;
            }
        }
        return mergedList;
    }
};

int main(int argc, char* argv[]) {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    for(int i = 2; i < 6; i++) {
        p1->next = new ListNode(i);
        p2->next = new ListNode(i*2);
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = new ListNode(100);
    printList(l1);
    printList(l2);
    printList(Solution().mergeTwoLists(l1, l2));
}
