#include <stdio.h>
#include <string.h>
#include "../include/graph.h"

/* City list */
static char cities[MAX_CITIES][20] = {
    "DELHI", "MUMBAI", "BENGALORE", "CHENNAI", "HYDERABAD",
    "VISAKHAPATNAM", "GOA", "KOLKATA", "AHEMDABAD",
    "GUWAHATI", "GORAKHPUR"
};

/* Adjacency matrix */
static int adj[MAX_CITIES][MAX_CITIES] = {0};

static int getCityIndex(char *name) {
    for (int i = 0; i < MAX_CITIES; i++) {
        if (strcmp(cities[i], name) == 0)
            return i;
    }
    return -1;
}

void addRoute(char *src, char *dest) {
    int u = getCityIndex(src);
    int v = getCityIndex(dest);

    if (u != -1 && v != -1)
        adj[u][v] = adj[v][u] = 1; // undirected graph
}

void showAirportMap() {
    printf("\n================ INDIA AIRPORT ROUTE MAP ================\n\n");

    printf("                                       [DELHI]\n");
    printf("                                         |  \\\n");
    printf("                                         |   \\_________[KOLKATA]\n");
    printf("                                         |               |\n");
    printf("                          [GUWAHATI]---[GORAKHPUR]      [AHEMDABAD]\n");
    printf("                                                        |\n");
    printf("                                  [MUMBAI] ------ [HYDERABAD] ------ [VISAKHAPATNAM]\n");
    printf("                                     |                |\n");
    printf("                                    [GOA]         [BENGALORE]\n");
    printf("                                                       |\n");
    printf("                                                   [CHENNAI]\n");

    printf("\n---------------------------------------------------------\n");
    printf("Graph Connections:\n\n");

    for (int i = 0; i < MAX_CITIES; i++) {
        printf("%-12s -> ", cities[i]);
        for (int j = 0; j < MAX_CITIES; j++) {
            if (adj[i][j])
                printf("%s ", cities[j]);
        }
        printf("\n");
    }

    printf("---------------------------------------------------------\n");
}
