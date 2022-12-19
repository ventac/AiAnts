#ifndef BUFFER_H
#define BUFFER_H
#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)




void ShowTable(int **map,int row,int col);
void FillTable(int **map,int row,int col);

#endif