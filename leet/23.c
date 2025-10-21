#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y)
        return -1;
    if (x == y)
        return 0;
    return 1;
}

struct ListNode* initList(int val) {
    struct ListNode* l = malloc(sizeof(struct ListNode));
    l->val = val;
    return l;
}

void addToList(struct ListNode **list, int val) {
    if (!*list) {
        *list = initList(val);
    } else {
        struct ListNode *l = *list;
        while(l->next) 
            l = l->next;
        l->next = initList(val);
    }
}

void freeList(struct ListNode **list) {
    struct ListNode *tmp;
    while(*list) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
    *list = NULL;
}

void printList(struct ListNode *list) {
    while(list->next) {
        printf("%d->", list->val);
        list = list->next;
    }
    printf("%d\n", list->val);
}

int totalElems(struct ListNode *list) {
    int nr = 0;
    while(list) {
        nr++;
        list = list->next;
    }
    return nr;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *list;
    int nr = 0;
    if (!lists || listsSize == 0)
        return NULL;
    for (int i = 0 ; i < listsSize ; i++) {
        list = lists[i];
        while(list) {
            nr++;
            list = list->next;
        }
    }

    if (nr == 0)
        return NULL;
    
    int *v = malloc(sizeof(int) * nr);

    int cnt = 0;

    for (int i = 0 ; i < listsSize ; i++) {
        list = lists[i];
        while (list) {
            v[cnt++] = list->val;
            list = list->next;
        }
    }
    qsort(v, nr, sizeof(int), cmp);

    struct ListNode *mergedKLists = NULL;
    struct ListNode *tail = NULL;
    for (int i = 0 ; i < nr ; i++) {
        list = malloc(sizeof(struct ListNode));
        list->val = v[i];
        list->next = NULL;
        if (!mergedKLists) {
            mergedKLists = list;
        } else {
            tail->next = list;
        }
        tail = list;
    }
    free(v);
    return mergedKLists;
}
