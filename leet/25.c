#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reverseList(struct ListNode** head) {
    struct ListNode *next = (*head)->next;
    (*head)->next = NULL;
    while(next) {
        struct ListNode *tmp = next;
        next = next->next;
        tmp->next = *head;
        *head = tmp;
    }
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int total = 0;
    struct ListNode *l = head;
    struct ListNode *tail = head;

    if (k == 1)
        return head;
    
    while (l) {
        total++;
        l = l->next;
    }

    int totalReversals = total / k;
    int first = 1;

    l = head;
    struct ListNode *reversedList = NULL;
    struct ListNode *last = NULL;

    for (int i = 0 ; i < totalReversals ; i++) {
        tail = l;
        for (int j = 0 ; j < k - 1 ; j++)
            tail = tail->next;

        struct ListNode *after = tail->next;

        tail->next = NULL;
        tail = l;

        reverseList(&l);

        if (first) {
            reversedList = l;
            first = 0;
            last = l;
        } else {
            while(last->next)
                last = last->next;
            last->next = l;
        }

        l = after;
        
        if (i == totalReversals - 1) {
            while(last->next)
                last = last->next;
            last->next = after;
        }
    }

    return reversedList;
}