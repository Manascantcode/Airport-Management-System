#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/flight.h"

Flight *head = NULL;

Flight* newFlight(int n, char* s, char* d, int du, float fare) {
    Flight* f = (Flight*)malloc(sizeof(Flight));
    f->no = n;
    strcpy(f->src, s);
    strcpy(f->dest, d);
    f->dur = du;
    f->fare = fare;
    f->next = NULL;
    return f;
}

void addFlight(Flight* f) {
    f->next = head;
    head = f;
}

void showFlights() {
    if (!head) {
        puts("No flights available.");
        return;
    }

    puts("\nAvailable Flights:");
    for (Flight* p = head; p; p = p->next) {
        printf(" %d: %s -> %s (%d min)\nFare: Rs %.2f\n",
               p->no, p->src, p->dest, p->dur, p->fare);
    }
}

Flight* findFlight(int no) {
    for (Flight* p = head; p; p = p->next) {
        if (p->no == no)
            return p;
    }
    return NULL;
}
