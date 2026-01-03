#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/flight.h"
#include "../include/passenger.h"
#include "../include/graph.h"

int main() {
    printf("============================\n");
    printf(" Airport Management System\n");
    printf("============================\n");

    /* Predefined flights */
    addFlight(newFlight(101, "DELHI", "MUMBAI", 120, 5500));
    addFlight(newFlight(202, "MUMBAI", "BENGALORE", 100, 4500));
    addFlight(newFlight(303, "DELHI", "HYDERABAD", 150, 6000));
    addFlight(newFlight(404, "BENGALORE", "CHENNAI", 90, 5000));
    addFlight(newFlight(505, "GORAKHPUR", "DELHI", 180, 8000));
    addFlight(newFlight(606, "HYDERABAD", "VISAKHAPATNAM", 180, 4000));
    addFlight(newFlight(707, "AHEMDABAD", "GORAKHPUR", 120, 3500));
    addFlight(newFlight(007, "GORAKHPUR", "GUWAHATI", 150, 3500));
    addFlight(newFlight(808, "GOA", "MUMBAI", 180, 4000));
    addFlight(newFlight(909, "KOLKATA", "DELHI", 180, 12000));

    /* Build airport graph */
    for (Flight *f = head; f; f = f->next)
        addRoute(f->src, f->dest);

    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Show Airport Map\n");
        printf("2. Show All Flights\n");
        printf("3. Book Flight\n");
        printf("4. Find Passenger by ID\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showAirportMap();
        }
        else if (choice == 2) {
            showFlights();
        }
        else if (choice == 3) {
            showFlights();
            int fno;
            printf("\nEnter flight number to book: ");
            scanf("%d", &fno);

            Flight* f = findFlight(fno);
            if (!f) {
                printf("Invalid flight number.\n");
                continue;
            }

            Passenger* p = (Passenger*)malloc(sizeof(Passenger));

            printf("Enter passenger name: ");
            scanf("%s", p->name);

            printf("Enter mobile number (as ID): ");
            scanf("%d", &p->id);

            printf("Enter luggage weight (kg): ");
            scanf("%f", &p->luggage);

            strcpy(p->src, f->src);
            strcpy(p->dest, f->dest);
            p->flightNo = f->no;
            p->fare = f->fare;

            /* Luggage charge logic */
            p->charge = (p->luggage > 22) ? (p->luggage - 22) * 400 : 0;

            addPassenger(p);

            printf("\nBooking Successful!\n");
            printf("Passenger: %s | Flight: %d | Total Fare: Rs %.2f\n",
                   p->name, p->flightNo, p->fare + p->charge);
        }
        else if (choice == 4) {
            int id;
            printf("Enter passenger ID: ");
            scanf("%d", &id);

            Passenger* p = getPassenger(id);
            if (p) {
                printf("\nPassenger Found:\n");
                printf("Name: %s\nFlight: %d\nRoute: %s -> %s\n",
                       p->name, p->flightNo, p->src, p->dest);
            } else {
                printf("Passenger not found.\n");
            }
        }
        else if (choice == 5) {
            printf("Exiting system...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
