#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/passenger.h"

/* Hash table */
static Passenger* H[HASH] = {NULL};

static int h(int id) {
    return abs(id % HASH);
}

void addPassenger(Passenger* p) {
    int k = h(p->id);
    p->next = H[k];
    H[k] = p;
}

Passenger* getPassenger(int id) {
    for (Passenger* p = H[h(id)]; p; p = p->next) {
        if (p->id == id)
            return p;
    }
    return NULL;
}
