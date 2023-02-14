#include "IHM.h"

// Var globale
unsigned char grille[7][6];
unsigned char winner = 0;
unsigned char current_player = 1;

void reset_grille() {
    unsigned char x,y;
    for (x=0;x<7;x++) {
        for (y=0;y<6;y++) {
            grille[x][y] = 0;
        }
    }
}

unsigned char is_avaible() {

}


void Demarre_puissance4() {
    reset_grille();
    display_grille(grille);
    
}