#include <stdlib.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* tail = result;

        int flag = 0;
        while(l1 != NULL || l2 != NULL) {
            int val;
            if(l1 == NULL) val = l2->val;
            else if(l2 == NULL) val = l1->val;
            else val = l1->val + l2->val;

            int valTmp = val + flag;
            if(valTmp >= 10) {
                flag = valTmp / 10;
                valTmp %= 10;
            }
            else {
                flag = 0;
            }

            if(result == NULL) {
                result = new ListNode(valTmp);
                tail = result;
            }
            else {
                tail->next = new ListNode(valTmp);
                tail = tail->next;
            }

            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }
        if(flag) {
            tail->next = new ListNode(flag);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    ListNode l1(2);
    ListNode l11(4), l12(3);;
    l1.next = &l11;
    l1.next->next = &l12;

    ListNode l2(5);
    ListNode l21(6), l22(4);;
    l2.next = &l21;
    l2.next->next = &l22;

    ListNode* result = Solution().addTwoNumbers(&l1, &l2);

    while(result != NULL) {
        cout<<result->val<<endl;
        result = result->next;
    }
}

