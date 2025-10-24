#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;

};

struct ListNode* swapPairs(struct ListNode* head) {

    struct ListNode *swapped = NULL;

    if (!head)
        return NULL;
    if (!head->next)
        return head;

    struct ListNode *last, *crr, *next;
    crr = head;
    next = head->next;
    last = NULL;

    while (next) {
        struct ListNode *tmp = next;
        next = next->next;
        crr->next = tmp->next;
        tmp->next = crr;
        if (!swapped)
            swapped = tmp;
        if (last)
            last->next = tmp;
        last = crr;
        crr = crr->next;
        if(next)
            next = next->next;
    }
    return swapped;
}