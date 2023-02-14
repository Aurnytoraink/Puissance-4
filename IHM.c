#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IHM.h"


// tab est un tableau à deux dim
void display_grille(unsigned char tab[][6])
{
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

unsigned char ask_user(unsigned char current_player)
{   
    unsigned char selected_column;
    printf("Joueur %d : À ton tours !", current_player);
    printf("Choix de la colonne : ");
    scanf("%c", &selected_column);
    return selected_column;
}