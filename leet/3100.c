#include <stdio.h>
#include <stdlib.h>

int maxBottlesDrunk(int numBottles, int numExchange) {
    int bottlesDrunk = numBottles;
    int emptyBottles = numBottles;
    numBottles = 0;
    while (emptyBottles >= numExchange) {
        emptyBottles++;
        bottlesDrunk++;
        emptyBottles -= numExchange;
        numExchange++;
    }
    return bottlesDrunk;
}

int main() {
    printf("%d\n", maxBottlesDrunk(13, 6));
}