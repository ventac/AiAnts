#include "Ant.h"
#include "AiAnts.h"

// Random va définir la direction au début
// TODO :  Ajouter ça dans une Structure ant
// Futurement: void MoveAnt(int direction, ant ant, pris nourriture? TRUE/FALSE -> Augmente le
// score/ qtt trace)
void MoveAnt(int direction, int **x_ant, int **y_ant, int **table[ROW_QTT][COL_QTT]){    

    // TODO : Eviter contact avec le mur
    // Modifier la valeur de x et y (-1) pour éviter que ça dépasse
    // sinon, changer direction
    // sinon, rester dans default jusqu'au prochain boucle

    LeaveTrace(**x_ant,**y_ant, table);  // -1 pour pas dépasser la taille du tableau

    switch (direction)
    {
    case 1: // ↑                
        **y_ant -= 1;// La bouger
        break;
    case 2: // ⬈
        **y_ant -= 1;
        **x_ant += 1;  
        break;
    case 3: // →
        **x_ant += 1;  
        break;
    /*case 4: // ⬊
        **y_ant += 1;
        **x_ant += 1;  
        break;*/
    case 5: // ↓
        **y_ant += 1;
        break;
    case 6: // ⬋
        **y_ant += 1;
        **x_ant -= 1; 
        break;
    case 7: // ←
        **x_ant -= 1;  
        break;
    case 8: // ⬉
        **y_ant -= 1;
        **x_ant -= 1;  
        break; 
    default:
        break;
    }

    // La bouger effectivement;
    **table[**y_ant][**x_ant] = ANT;
}

// Où la fourmis va laisser son trace
void LeaveTrace(int x, int y, int **table[ROW_QTT][COL_QTT]){
    **table[y][x] = **table[y][x] - ANT + 1; // Efface la fourmis et ajoute la qtt
}
