#ifndef AIANTS_H
#define AIANTS_H
#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)
#include  <string.h>
#include <stdbool.h>

#define COL_QTT 8
#define ROW_QTT 8
#define ANT 500
#define QTT_ANTC 1

// struct for ants
typedef struct Ants{
    int direction; // where is the head pointing? +x, -x, +y, -y
    int pher_toFood; // number of pheromones left when going to pick food
    int pher_toHome; // number of pheromones left when going back home
    bool HasFood;
    int pos_x; // current x position on the map
    int pos_y; // current y position on the map
}Ants;

// struct for each tile of the map
typedef struct Tile{
    int num_toFood; // number of pheromones on the tile when going to pick food
    int num_toHome; // number of pheromones on the tile when going back home
    bool obstacle; // True if there's an obstacle on the tile
}Tile;

// informations needed for the map
typedef struct Map{
    int width;
    int lenght;
    Tile tile;
}Map;

#endif