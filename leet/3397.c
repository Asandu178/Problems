#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y)
        return -1;
    if (x == y)
        return 0;
    return 1;
}

int max(int a, int b) {
    return (a > b ? a : b);
}

int min(int a, int b) {
    return (a > b ? b : a);
}

int maxDistinctElements(int *nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int prev = INT_MIN;
    int cnt = 0;
    for (int i = 0 ; i < numsSize ; i++) {
        int curr = min(max(prev + 1, nums[i] - k), nums[i] + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
}