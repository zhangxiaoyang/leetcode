#include <iostream>
#include <stack>
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
    cout<<'\n';
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* p = head;
        while(p) {
            s.push(p);
            p = p->next;
        }

        int length = (int)s.size();
        if(length > n && n > 0) {
            for(int i = 0; i < n; i++) {
               s.pop();
            }
            ListNode* removedFront = s.top();
            ListNode* tmp = removedFront->next->next;
            delete removedFront->next;
            removedFront->next = tmp;
        }
        else if(length == n) {
            ListNode* tmp = head->next; 
            delete head;
            head = tmp;
        }

        return head;
    }
};

int main(int argc, char* argv[]) {
    //init
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i <= 5; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    printList(head);

    int n = 2;
    printList(Solution().removeNthFromEnd(head, n));
}
