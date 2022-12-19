#ifndef BUFFER_H
#define BUFFER_H
#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)


#define COL_QTT 8
#define ROW_QTT 8
#define F 500  // ça va répresenter numériquement la fourmis, on peut changer après par -1
#define QTT_ANTC 1

void ShowTable(int **map,int row,int col);
void FillTable(int **map,int row,int col);

#endif