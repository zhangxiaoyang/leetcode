#include <iostream>
using namespace std;

#include <stdlib.h>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void printList(RandomListNode *head) {
    while (head != NULL) {
        cout<<head->label<<' ';
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    void copyToList(RandomListNode *head) {
        RandomListNode *p = head;
        while (p != NULL) {
            RandomListNode *tmp = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = tmp;
            p = p->next->next;
        }
    }
    void copyRandomField(RandomListNode *head) {
        RandomListNode *p = head;
        while (p != NULL) {
            if (p->random != NULL)
                p->next->random = p->random->next;
            p = p->next->next;
        }
    }
    RandomListNode *splitCopliedList(RandomListNode *head) {
        RandomListNode *p = head;
        RandomListNode dummy(0);
        RandomListNode *q = &dummy;
        while (p != NULL) {
            q->next = p->next;
            p->next = p->next->next;
            p = p->next;
            q = q->next;
        }
        return dummy.next;

    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;

        copyToList(head);
        copyRandomField(head);
        return splitCopliedList(head);
    }
};

int main(int argc, char* argv[]) {
    RandomListNode *head = new RandomListNode(-1);
    printList(Solution().copyRandomList(head));
}
