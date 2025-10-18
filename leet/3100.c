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