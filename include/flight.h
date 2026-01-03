#ifndef FLIGHT_H
#define FLIGHT_H

//Flights (Linked List)
typedef struct Flight {
    int no, dur;
    char src[20], dest[20];
    float fare;
    struct Flight *next;
} Flight;

// Function declarations
Flight* newFlight(int n, char* s, char* d, int du, float fare);
void addFlight(Flight* f);
void showFlights();
Flight* findFlight(int no);

// Head pointer (shared across files)
extern Flight *head;

#endif
