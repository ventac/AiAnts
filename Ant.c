#include "AiAnts.h"
#include "Ant.h"



// Où la fourmis va laisser son trace
/*void LeaveTrace(int x, int y){
    table[y][x] = table[y][x] - F + 1; // Efface la fourmis et ajoute la qtt
}*/

// Futurement: void MoveAnt(int direction, ant ant, pris nourriture? TRUE/FALSE -> Augmente le
// score/ qtt trace)
// Mouvement pour chercher la nouriture. Après la trouver, elle va utiliser le trace pour rétourner
void MoveAnt(int direction, int **x_ant, int **y_ant){    

    //LeaveTrace(**x_ant,**y_ant);

    switch (direction)
    {
    case 1: // ↑                
        **y_ant -= 1;  // La bouger
        break;
    case 2: // ⬈
        **y_ant -= 1;
        **x_ant += 1;  
        break;
    case 3: // →
        **x_ant += 1;  
        break;
    case 4: // ⬊
        **y_ant += 1;
        **x_ant += 1;  
        break;
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

    // Eviter colisions y
    if(**y_ant < 0){
        **y_ant = 0;
    }else if(**y_ant > ROW_QTT){
        **y_ant = ROW_QTT;
    }
    
    // Eviter colisions x
    if(**x_ant < 0){
        **x_ant = 0;
    }else if(**x_ant > COL_QTT){
        **x_ant = COL_QTT;
    }

    // La bouger effectivement;
    table[**y_ant][**x_ant] = F;
}
