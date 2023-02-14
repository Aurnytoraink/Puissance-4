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
            case 0: // vide
            {
                line[i] = '#';
            }
            break;

            case 1: // Joueur 1
            {
               line[i] = 'X';
            }
            break;

            case 2: // Joueur 2
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

int ask_user(int current_player)
{   
    int selected_column;
    printf("Joueur %d : À ton tours !\n", current_player);
    printf("Choix de la colonne : ");
    scanf("%d", &selected_column);
    return selected_column;
}

void column_out_of_range() {
    printf("Veuillez choisir une colonne entre 1 et 7");
}

void no_more_space_avaible() {
    printf("La colonne choisie est pleine!\nVeuillez en choisir une autre !");
}

