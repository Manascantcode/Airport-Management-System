#ifndef PASSENGER_H
#define PASSENGER_H

#define HASH 31

/* -------- Passenger (Hash Table) -------- */
typedef struct Passenger {
    int id;
    char name[20];
    float luggage, charge, fare;
    int flightNo;
    char src[20], dest[20];
    struct Passenger* next;
} Passenger;

/* Function declarations */
void addPassenger(Passenger* p);
Passenger* getPassenger(int id);

#endif
