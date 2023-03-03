#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IHM.h"


// tab est un tableau à deux dim
void display_grille(int tab[][6])
{
    printf("\n\n1 2 3 4 5 6 7\n");
    char line[13] = {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'};
    // line = malloc (sizeof (*line) * 8);
    int x, y, i;
    for (y = 0; y < 6; y++)
    {
        for (x = 0, i = 0; x < 7, i<13; x++, i = i + 2)
        {
            switch (tab[x][y])
            {
            case -1: // vide
            {
                line[i] = '#';
            }
            break;

            case 0: // Joueur 1
            {
               line[i] = 'X';
            }
            break;

            case 1: // Joueur 2
            {
                line[i] = 'O';
            }
            break;

            }
        }
        // line[i]
        printf("%s\n",line);
    }
}

int ask_user_column(int current_player)
{   
    int selected_column = 0;
    printf("Joueur %d : À ton tour !\n", current_player + 1);
    do
    {
        printf("Choix de la colonne : ");
        scanf("%d", &selected_column);
    } while (selected_column<1 || selected_column>7);
    return selected_column - 1;
}

void column_out_of_range() {
    printf("Veuillez choisir une colonne entre 1 et 7");
}

void no_more_space_avaible() {
    printf("La colonne choisie est pleine!\nVeuillez en choisir une autre !");
}

void display_winner(int player) {
    printf("Bravo joueur %d !\nTu es vraiment intelligent.\nTiens, tu as gagné un cookie !",player + 1);
}

void display_full() {
    printf("Plus de place !\nVous êtes à égalité !");
}